#----------------------------------------------------------------
# Generated CMake target import file for configuration "release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::Net" for configuration "release"
set_property(TARGET Poco::Net APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Poco::Net PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libPocoNet.so.60"
  IMPORTED_SONAME_RELEASE "libPocoNet.so.60"
  )

list(APPEND _IMPORT_CHECK_TARGETS Poco::Net )
list(APPEND _IMPORT_CHECK_FILES_FOR_Poco::Net "${_IMPORT_PREFIX}/lib/libPocoNet.so.60" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
