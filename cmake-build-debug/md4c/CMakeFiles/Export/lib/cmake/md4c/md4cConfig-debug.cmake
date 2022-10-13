#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "md4c" for configuration "Debug"
set_property(TARGET md4c APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(md4c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libmd4c.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS md4c )
list(APPEND _IMPORT_CHECK_FILES_FOR_md4c "${_IMPORT_PREFIX}/lib/libmd4c.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
