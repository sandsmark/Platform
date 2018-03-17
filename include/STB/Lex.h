//------------------------------------------------------------------------------
// Copyright (c) 2018 John D. Haughton
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------

#ifndef STB_LEX_H
#define STB_LEX_H

#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>

#include "PLT/File.h"

namespace STB {


class Lex
{
public:
   //! Try and match a single character
   bool isMatch(char token)
   {
      if (token == first())
      {
         sink();
         return true;
      }

      return false;
   }

   //! Try and match a string
   bool isMatch(const char* token)
   {
      char ch = first();

      for(unsigned i=0; token[i] != '\0'; i++)
      {
         if (ch != token[i])
         {
            for(unsigned j=0; j<i; j++)
            {
               unsink(token[j]);
            }

            return false;
         }

         sink();
         ch = next();
      }

      return true;
   }

   //! Try and match an identifier
   bool isMatchIdent(std::string& ident)
   {
      char ch = first();
      if (!isalpha(ch)) return false;
      sink();

      ident = ch;
      while(true)
      {
         ch = next();
         if (!isalnum(ch) && (ch != '_') && (ch != ':') && (ch != '-')) return true;

         sink();
         ident.push_back(ch);
      }
   }

   //! Try and match a literal string
   bool isMatch(std::string& value)
   {
      char ch = first();
      if (ch != '"') return false;
      sink();

      value = "";
      while(true)
      {
         if (isEof()) error("terminating \" exepcted");

         ch = next();
         sink();
         if (ch == '"') return true;

         value.push_back(ch);
      }
   }

   //! Try and match a literal signed integer
   bool isMatch(signed int& value)
   {
      int      sign = +1;
      char     ch   = first();
      unsigned base = 10;

           if (ch == '-')   { value = 0; sign = -1; }
      else if (ch == '+')   { value = 0;            }
      else if (isdigit(ch)) { value = ch - '0';     }
      else                  { return false;         }

      sink();

      while(!isEof())
      {
         ch = next();
         if (!isdigit(ch))
         {
            break;
         }

         sink();
         value = value * base + ch - '0';
      }

      value *= sign;
      return true;
   }

   //! Try and match a literal float
   bool isMatch(double& value)
   {
      int  sign = +1;
      char ch   = first();

           if (ch == '-')   { value = 0.0; sign = -1; }
      else if (ch == '+')   { value = 0.0;            }
      else if (isdigit(ch)) { value = ch - '0';       }
      else                  { return false;           }

      sink();

      double denominator = 1.0;

      while(!isEof())
      {
         ch = next();
         if (ch == '.')
         {
            denominator = 10.0;
            sink();
         }
         else if (!isdigit(ch))
         {
            break;
         }
         else
         {
            sink();
            if (denominator == 1.0)
            {
               value = value * 10.0 + ch - '0';
            }
            else
            {
               value += (ch - '0') / denominator;
               denominator = denominator * 10.0;
            }
         }
      }

      value *= sign;

      if ((ch == 'e') || (ch == 'E'))
      {
         sink();

         int exp;

         if (isMatch(exp))
         {
            value = value * pow(10.0, exp);
         }
         else
         {
            unsink(ch);
         }
      }

      return true;
   }

   //! Match a single character
   void match(char token)
   {
      if (!isMatch(token)) error("'%c' expected", token);
   }

   //! Match a string
   void match(const char* token)
   {
      if (!isMatch(token))  error("'%s' expected", token);
   }

   //! Match an identiier
   void matchIdent(std::string& ident)
   {
      if (!isMatchIdent(ident)) error("identifier epxected");
   }

   //! Match a literal string
   void match(std::string& string)
   {
      if (!isMatch(string)) error("literal string expected");
   }

   //! Match a integer literal
   void match(int& value)
   {
      if (!isMatch(value)) error("literal integer expected");
   }

   //! Match a floating point literal
   void match(double& value)
   {
      if (!isMatch(value)) error("literal float expected");
   }

   //! Report a file error
   void error(const char* format, ...)
   {
      fprintf(stderr, "\nERROR %s:%u - ", getSource().c_str(), line_no);

      va_list ap;
      va_start(ap, format);
      vfprintf(stderr, format, ap);
      va_end(ap);

      fprintf(stderr, "\n");

      exit(1);
   }

   //! Return the next non-whitespace character from the input stream
   char first()
   {
      while(true)
      {
         char ch = next();
         if (!isspace(ch)) return ch;
         sink();
      }
   }

   //! Return the next character from the input stream
   char next()
   {
      if (buffer.empty())
      {
         char ch;
         if (!getChar(ch)) return '\0';
         buffer.push_back(ch);
         if (buffer.back() == '\n') line_no++;
      }

      return buffer.back();
   }

   //! Sink the next character from the input stream
   void sink()
   {
      buffer.pop_back();
   }

   //!
   void unsink(char ch)
   {
      buffer.push_back(ch);
   }

protected:
   Lex() {}

   virtual std::string getSource() const = 0;
   virtual bool        isEof() const = 0;
   virtual bool        getChar(char& ch) = 0;

private:
   unsigned           line_no{1};
   std::vector<char>  buffer;
};


class File : public Lex
{
public:
   File(const std::string& filename)
      : file(filename.c_str(), "r")
   {
      if (!file.isOpen())
      {
         error("Failed to open file '%s'", filename.c_str());
      }
   }

   // Implement Lex

   virtual std::string getSource() const override { return file.getFilename(); }
   virtual bool        isEof() const override     { return file.isEof(); }
   virtual bool        getChar(char& ch) override { return file.getChar(ch); }

private:
   PLT::File    file;
};


class String : public Lex
{
public:
   String(const std::string& string_)
      : string(string_)
   {}

   // Implement Lex

   virtual std::string getSource() const override { return ""; }
   virtual bool        isEof() const override     { return pos >= string.size(); }

   virtual bool getChar(char& ch) override
   {
      if (isEof()) return false;
      ch = string[pos++];
      return true;
   }

private:
   size_t       pos{0};
   std::string  string{};
};


} // namsepace STB


#endif