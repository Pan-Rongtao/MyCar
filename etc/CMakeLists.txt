# 1. Project Name

project(etc)

# 2. Platform Env (Include/Lib Path, C/CXX/LD FLAGS)



# 3. Sub Projects


# 5. Project Install
file(GLOB RES *.db *.conf *.jpg)
install(FILES ${RES} DESTINATION ${CMAKE_INSTALL_ETCDIR})

