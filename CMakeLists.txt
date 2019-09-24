
# 0. CMake Defs

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

cmake_policy(VERSION 2.6)

# 1. Project Name

project(mycar)

# 2. Env (Include/Lib Path, C/CXX/LD FLAGS)
#set(CMAKE_DEBUG_POSTFIX d)
ADD_DEFINITIONS( -D_WIN32_WINNT=0x601 -DWIN32_LEAN_AND_MEAN )

if ("${CMAKE_SYSTEM_NAME}" STREQUAL QNX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

if ("${CMAKE_INSTALL_PREFIX}" STREQUAL "")
	SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)
endif()

SET(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_PREFIX}/include)
SET(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/lib)
SET(CMAKE_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)
SET(CMAKE_INSTALL_ETCDIR ${CMAKE_INSTALL_PREFIX}/etc)
SET(CMAKE_INSTALL_DOCDIR ${CMAKE_INSTALL_PREFIX}/doc)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/include)
if(WIN32)
	link_directories(${CMAKE_SOURCE_DIR}/3rdparty/lib/win32)
else()
	if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL x86_64)
		link_directories(${CMAKE_SOURCE_DIR}/3rdparty/lib/linux-x11)
	else()
		link_directories(${CMAKE_SOURCE_DIR}/3rdparty/lib/linux-arm)
	endif()
endif()

# 4. Sub Projects

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(3rdparty)
add_subdirectory(etc)
#add_subdirectory(doc)

# 5. Project Install
