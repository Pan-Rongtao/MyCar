
####################################################################################################

# Company       : Huizhou Desay SV Automotive Co., Ltd.

# Division      : Automotive Electronics, Desay Corporation

# Business Unit : Central Technology

# Department    : Advanced Development (Huizhou)

####################################################################################################

# 1. Project Name

project(carservice)

# 2. Project Env (Include/Lib Path, C/CXX/LD FLAGS)

# 3. Project Build

set(BIN_NAME "carservice")

file(GLOB SRC_FILES "*.h" "*.cpp")

add_executable(${BIN_NAME} ${SRC_FILES})
target_link_libraries(${BIN_NAME} libcore libcar optimized PocoFoundation debug PocoFoundationd optimized PocoJSON debug PocoJSONd)

# 4. Project Install
if(WIN32)
    install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR}/debug CONFIGURATIONS debug)
    install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR}/release CONFIGURATIONS release)
else()
	install(TARGETS ${BIN_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
