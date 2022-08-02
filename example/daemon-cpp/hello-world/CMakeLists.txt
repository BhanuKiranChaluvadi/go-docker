# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.14)

# Set the project name
project (hello_world)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/Daemon.cpp
    src/Data.cpp
    src/XMLRPCAbyssServer.cpp
    src/XMLRPCMethods.cpp
)

############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(HelloWorld ${SOURCES})

# Set the directories that should be included in the build command for this target
target_include_directories(HelloWorld
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

# link the new target with other targets/library
target_link_libraries(HelloWorld
    PRIVATE 
        xmlrpc_server_abyss++
        xmlrpc_server_abyss
        xmlrpc_server_pstream++
        xmlrpc_server
        xmlrpc_abyss
        xmlrpc_server++
        xmlrpc++
        xmlrpc
        xmlrpc_packetsocket
        xmlrpc_xmlparse
        xmlrpc_xmltok
        xmlrpc_util
        curl      
)