PROJECT(projecteuler)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1.0 FATAL_ERROR)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ftrapv")

INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/src/")

FILE(GLOB_RECURSE SRC_LIST "${CMAKE_SOURCE_DIR}/src/*.cpp")

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
