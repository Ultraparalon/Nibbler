CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(nibbler)

include_directories("${PROJECT_SOURCE_DIR}/dynsdl")
add_subdirectory(dynsdl)

include_directories("${PROJECT_SOURCE_DIR}/dynsfml")
add_subdirectory(dynsfml)

file(GLOB SOURCES sources/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(includes)										
