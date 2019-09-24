
####################################################################################################

# Company       : Huizhou Desay SV Automotive Co., Ltd.

# Division      : Automotive Electronics, Desay Corporation

# Business Unit : Central Technology

# Department    : Advanced Development (Huizhou)

####################################################################################################

# 1. Project Name

project(client)

# 2. Project Env (Include/Lib Path, C/CXX/LD FLAGS)

# 3. Project Build

set(BIN_NAME "client")

file(GLOB SRC_FILES "*.h" "*.cpp")

add_executable(${BIN_NAME} ${SRC_FILES})
set_target_properties(${BIN_NAME} PROPERTIES OUTPUT_NAME uit.client)
if(WIN32)
	target_link_libraries(${BIN_NAME} core RcfLib)
else()
	target_link_libraries(${BIN_NAME} core PocoNet RcfLib pthread dl uuid)
endif()

# 4. Project Install
if(WIN32)
    install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR}/debug CONFIGURATIONS debug)
    install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR}/release CONFIGURATIONS release)
else()
	install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

