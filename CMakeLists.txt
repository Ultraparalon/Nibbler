CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(nibbler)

file(GLOB SOURCES sources/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
