cmake_minimum_required( VERSION 3.0)

project(dynsfml)

find_package(SFML 2.5 REQUIRED system window graphics network audio)

set(SRC sources/)
set(SOURCE_LIB	${SRC}DynamicSfml.cpp
				${SRC}SfmlGui.cpp
				${SRC}SfmlInput.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_LIB})
include_directories(includes)

# include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}	sfml-system
										sfml-window
										sfml-graphics
										sfml-network
										sfml-audio)
