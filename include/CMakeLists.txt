# 1. Project Name

project(include)

# 2. Platform Env (Include/Lib Path, C/CXX/LD FLAGS)



# 3. Sub Projects


# 5. Project Install
install(DIRECTORY core DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY server DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
