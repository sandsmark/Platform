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

project(${app})

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

if(DEFINED ENV{PROJ_TARGET})
   set(target $ENV{PROJ_TARGET})
else()
   set(target ${CMAKE_SYSTEM_NAME})
endif()

# Use the host system as the default target
if(target STREQUAL "Darwin")
   set(target macOS)
endif()

execute_process(COMMAND uname -m
                OUTPUT_VARIABLE machine)
string(STRIP ${machine} machine)

execute_process(COMMAND git log --pretty=format:%H -n 1
                OUTPUT_VARIABLE commit)

include(${CMAKE_SOURCE_DIR}/Platform/Source/PLT/${target}/config.cmake)

#-------------------------------------------------------------------------------
# Build support

add_compile_options(-DPROJ_COMMIT=\"${commit}\")
add_compile_options(-DPROJ_VERSION=\"${version}\")
add_compile_options(-DPROJ_MACHINE=\"${machine}\")
add_compile_options(-DPROJ_TARGET_${target})

add_compile_options(-Wall)
add_compile_options(-Werror)

include_directories(Platform/include)

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

            ${platform_source})

set(platform_libs PLT ${platform_libs})

#-------------------------------------------------------------------------------
# Package support

if(DEFINED pkg_source)
   set(pkg_name ${app}_${target}_${machine}_${version}.tgz)

   add_custom_command(OUTPUT  ${pkg_name}
                      COMMAND tar cvfz ${pkg_name} ${pkg_source}
                      DEPENDS ${pkg_source})

   add_custom_target(package ALL DEPENDS ${pkg_name})
endif()
