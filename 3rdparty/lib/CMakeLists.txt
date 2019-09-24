# 1. Project Name

project(lib)

# 2. Env (Include/Lib Path, C/CXX/LD FLAGS)


# 4. Sub Projects

# 5. Project Install
if(MSVC)
	file(GLOB INSTALL_LIBS_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/win32/debug/*.dll ${CMAKE_CURRENT_SOURCE_DIR}/win32/debug/*.lib CONFIGURATIONS debug)
	file(GLOB INSTALL_LIBS_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/win32/release/*.dll ${CMAKE_CURRENT_SOURCE_DIR}/win32/release/*.lib CONFIGURATIONS release)
	install(FILES ${INSTALL_LIBS_DEBUG} DESTINATION ${CMAKE_INSTALL_LIBDIR}/debug CONFIGURATIONS debug)
	install(FILES ${INSTALL_LIBS_RELEASE} DESTINATION ${CMAKE_INSTALL_LIBDIR}/release CONFIGURATIONS release)
else()
	if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL x86_64)
		file(GLOB LIBS linux-x11/*.so*)
		install(FILES ${LIBS} DESTINATION ${CMAKE_INSTALL_LIBDIR})
	else()
		file(GLOB LIBS linux-arm/*.so*)
		install(FILES ${LIBS} DESTINATION ${CMAKE_INSTALL_LIBDIR})
	endif()
endif()
