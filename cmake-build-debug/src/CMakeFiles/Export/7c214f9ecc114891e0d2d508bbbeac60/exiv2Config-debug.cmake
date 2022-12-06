#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "exiv2-xmp" for configuration "Debug"
set_property(TARGET exiv2-xmp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(exiv2-xmp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libexiv2-xmp.a"
  )

list(APPEND _cmake_import_check_targets exiv2-xmp )
list(APPEND _cmake_import_check_files_for_exiv2-xmp "${_IMPORT_PREFIX}/lib/libexiv2-xmp.a" )

# Import target "exiv2lib" for configuration "Debug"
set_property(TARGET exiv2lib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(exiv2lib PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libexiv2.so.0.27.99.0"
  IMPORTED_SONAME_DEBUG "libexiv2.so.27"
  )

list(APPEND _cmake_import_check_targets exiv2lib )
list(APPEND _cmake_import_check_files_for_exiv2lib "${_IMPORT_PREFIX}/lib/libexiv2.so.0.27.99.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
