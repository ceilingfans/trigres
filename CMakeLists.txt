cmake_minimum_required(VERSION 3.20)
project(trigres)

#------------VARS------------#
set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SOURCE_FILES
        src/trigo.cpp
        src/util.cpp
        src/main.cpp)
set(HEADER_FILES
        include/trigo.hpp
        include/util.hpp)
#------------END VARS----------------#

#------------EXECUTABLE------------#
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
#------------END EXECUTABLE------------#

#------------FINDS------------#
#------------END FINDS------------#

#------------INCLUDES & LINK------------#
target_include_directories(${PROJECT_NAME} PRIVATE include)
include_directories(include)
#------------END INCLUDES & LINK------------#