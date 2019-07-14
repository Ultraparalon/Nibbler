CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(nibbler)

add_subdirectory(dynsdl)
add_subdirectory(dynsfml)
add_subdirectory(dynopengl)

file(GLOB SOURCES sources/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(includes)										
