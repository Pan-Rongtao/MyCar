#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::JSON" for configuration "release"
set_property(TARGET Poco::JSON APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Poco::JSON PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libPocoJSON.so.60"
  IMPORTED_SONAME_RELEASE "libPocoJSON.so.60"
  )

list(APPEND _IMPORT_CHECK_TARGETS Poco::JSON )
list(APPEND _IMPORT_CHECK_FILES_FOR_Poco::JSON "${_IMPORT_PREFIX}/lib/libPocoJSON.so.60" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
