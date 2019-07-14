cmake_minimum_required(VERSION 3.0)

project(dynopengl)



set(SRC sources/)

add_library(${PROJECT_NAME} ${SRC}DynamicOpengl.cpp)
include_directories(includes)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
# link_libraries(${GLFW_LIBRARY_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

#add_subdirectory(glfw)
#include_directories(glfw/include)

target_link_libraries(${PROJECT_NAME}	${OPENGL_LIBRARIES}
										${GLUT_LIBRARIES}
										glfw
										${GLEW_LIBRARIES})
