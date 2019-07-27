#-------------------------------------------------------------------------------
#  Copyright (c) 2019 John D. Haughton
# 
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
# 
#  The above copyright notice and this permission notice shall be included in
#  all copies or substantial portions of the Software.
# 
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#-------------------------------------------------------------------------------

# Construct a target platform specific build environment

project(${app} C CXX ASM)

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

set(PLT_TARGET "" CACHE STRING "The target platform")

# Determine target platform type
if(DEFINED ENV{PLT_TARGET})
   # Set via the PLT_TARGET environment variable
   # TODO do we need this now?
   set(PLT_TARGET $ENV{PLT_TARGET})

elseif(PLT_TARGET STREQUAL "")
   # Use the host system as the target
   set(PLT_TARGET ${CMAKE_SYSTEM_NAME})
endif()

# Translate macOSes confusing self description
if(PLT_TARGET STREQUAL "Darwin")
   set(PLT_TARGET macOS)
endif()

execute_process(COMMAND uname -m OUTPUT_VARIABLE PLT_machine)
string(STRIP ${PLT_machine} PLT_machine)

execute_process(COMMAND git log --pretty=format:%H -n 1 OUTPUT_VARIABLE PLT_commit)

include(${CMAKE_SOURCE_DIR}/Platform/Source/PLT/${PLT_TARGET}/config.cmake)

#-------------------------------------------------------------------------------
# Compiler flags

set(PLT_c_flags "${PLT_c_flags} -DPROJ_COMMIT=\\\"${PLT_commit}\\\"")
set(PLT_c_flags "${PLT_c_flags} -DPROJ_VERSION=\\\"${version}\\\"")
set(PLT_c_flags "${PLT_c_flags} -DPROJ_MACHINE=\\\"${PLT_machine}\\\"")
set(PLT_c_flags "${PLT_c_flags} -DPROJ_TARGET_${PLT_TARGET}")
set(PLT_c_flags "${PLT_c_flags} -Wall")
set(PLT_c_flags "${PLT_c_flags} -Werror")

set(CMAKE_ASM_FLAGS_RELEASE  ${PLT_asm_flags})
set(CMAKE_C_FLAGS_RELEASE    "-DNDEBUG -O3 ${PLT_c_flags}")
set(CMAKE_CXX_FLAGS_RELEASE  "-DNDEBUG -O3 ${PLT_cxx_flags} ${PLT_c_flags}")

set(CMAKE_ASM_FLAGS_DEBUG    ${PLT_asm_flags})
set(CMAKE_C_FLAGS_DEBUG      "-g -O0 ${PLT_c_flags}")
set(CMAKE_CXX_FLAGS_DEBUG    "-g -O0 ${PLT_cxx_flags} ${PLT_c_flags}")

include_directories(Platform/include)

#-------------------------------------------------------------------------------
# Build the platform library libPLT.a

add_library(PLT

            Platform/Source/STB/Option.cpp
            Platform/Source/STB/MidiDecoder.cpp
            Platform/Source/STB/Oil.cpp
            Platform/Source/STB/Deflate.cpp
            Platform/Source/STB/Zlib.cpp

            Platform/Source/GUI/FontLED11.cpp
            Platform/Source/GUI/FontLED22.cpp
            Platform/Source/GUI/FontNew8.cpp
            Platform/Source/GUI/FontTeletext18.cpp
            Platform/Source/GUI/FontTeletext15.cpp
            Platform/Source/GUI/FontTeletext12.cpp
            Platform/Source/GUI/FontTeletext9.cpp
            Platform/Source/GUI/BitmapPNG.cpp

            ${PLT_source})

set(PLT_libs PLT ${PLT_libs})

#-------------------------------------------------------------------------------
# Build the tiny C runtime library libtinyc.a

if(PLT_libs MATCHES ".*tinyc.*")
   include_directories(Platform/include/MTL/tinyc)

   add_library(tinyc
               Platform/Source/MTL/tinyc/abort.cpp
               Platform/Source/MTL/tinyc/abs.cpp
               Platform/Source/MTL/tinyc/atof.cpp
               Platform/Source/MTL/tinyc/atoi.cpp
               Platform/Source/MTL/tinyc/atol.cpp
               Platform/Source/MTL/tinyc/atoll.cpp
               Platform/Source/MTL/tinyc/clock.cpp
               Platform/Source/MTL/tinyc/delete.cpp
               Platform/Source/MTL/tinyc/exit.c
               Platform/Source/MTL/tinyc/fprintf.cpp
               Platform/Source/MTL/tinyc/getchar.cpp
               Platform/Source/MTL/tinyc/global_obj.cpp
               Platform/Source/MTL/tinyc/guard.c
               Platform/Source/MTL/tinyc/isalpha.cpp
               Platform/Source/MTL/tinyc/isdigit.cpp
               Platform/Source/MTL/tinyc/isspace.cpp
               Platform/Source/MTL/tinyc/malloc.cpp
               Platform/Source/MTL/tinyc/memcpy.cpp
               Platform/Source/MTL/tinyc/memmove.cpp
               Platform/Source/MTL/tinyc/memset.cpp
               Platform/Source/MTL/tinyc/printf.cpp
               Platform/Source/MTL/tinyc/pure_virtual.cpp
               Platform/Source/MTL/tinyc/putchar.cpp
               Platform/Source/MTL/tinyc/puts.cpp
               Platform/Source/MTL/tinyc/rand.cpp
               Platform/Source/MTL/tinyc/sin.c
               Platform/Source/MTL/tinyc/scanf.cpp
               Platform/Source/MTL/tinyc/sprintf.cpp
               Platform/Source/MTL/tinyc/strcat.cpp
               Platform/Source/MTL/tinyc/strchr.cpp
               Platform/Source/MTL/tinyc/strcmp.cpp
               Platform/Source/MTL/tinyc/strcpy.cpp
               Platform/Source/MTL/tinyc/strlen.cpp
               Platform/Source/MTL/tinyc/strncmp.cpp
               Platform/Source/MTL/tinyc/strncpy.cpp
               Platform/Source/MTL/tinyc/strrchr.cpp
               Platform/Source/MTL/tinyc/strtol.cpp
               Platform/Source/MTL/tinyc/strtoll.cpp
               Platform/Source/MTL/tinyc/strtoul.cpp
               Platform/Source/MTL/tinyc/strtoull.cpp
               Platform/Source/MTL/tinyc/time.cpp
               Platform/Source/MTL/tinyc/tinyc_init.c
               Platform/Source/MTL/tinyc/vfprintf.cpp
               Platform/Source/MTL/tinyc/vsprintf.cpp)
endif()

# TODO
#   env['startup'] = env.Install('lib/'+env['machine'], env['startup'])
#   env['script']  = env.Install('lib/'+env['machine'], env['script'])
#   env.Append(CPPPATH = env.Dir('include/MTL/board/'+target))
#   env.Append(LINKFLAGS = '-TPlatform/'+str(env['script'][0]))
#   env.Depends(env['startup'], env['script'])
#else:
#   env.Append(CPPPATH = env.Dir('include/MTL/board/stub'))
#
#-------------------------------------------------------------------------------
# Package support

if(DEFINED pkg_source)
   set(pkg_name ${app}_${PLT_TARGET}_${PLT_machine}_${version}.tgz)

   add_custom_command(OUTPUT  ${pkg_name}
                      COMMAND tar cvfz ${pkg_name} ${pkg_source}
                      DEPENDS ${pkg_source})

   add_custom_target(package ALL DEPENDS ${pkg_name})
endif()
