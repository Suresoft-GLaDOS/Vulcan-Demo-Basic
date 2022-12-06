# Install script for directory: /mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/exiv2" TYPE FILE FILES
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/basicio.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/bigtiffimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/bmpimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/config.h"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/convert.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/cr2image.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/crwimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/datasets.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/easyaccess.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/error.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/exif.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/exiv2.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/futils.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/gifimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/http.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/image.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/image_types.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/ini.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/iptc.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/jp2image.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/jpgimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/metadatum.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/mrwimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/orfimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/pgfimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/pngimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/preview.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/properties.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/psdimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/rafimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/rw2image.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/slice.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/tags.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/tgaimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/tiffimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/types.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/value.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/version.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/webpimage.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/xmp_exiv2.hpp"
    "/mnt/c/Users/sure/GLaDOS/Vulcan-Demo-Basic/include/exiv2/xmpsidecar.hpp"
    )
endif()

