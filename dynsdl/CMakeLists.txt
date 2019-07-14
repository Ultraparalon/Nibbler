cmake_minimum_required(VERSION 3.0)

project(dynsdl)

set(SRC sources/)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(SOURCE_LIB	${SRC}DynamicSdl.cpp
				${SRC}SdlGui.cpp
				${SRC}SdlInput.cpp
				${SRC}Texture.cpp
				${SRC}TextureFactory.cpp)

set(CMAKE_WINDOWS_EXPORT_ADD_SYMBOLS ON)

add_library(${PROJECT_NAME} SHARED ${SOURCE_LIB})
include_directories(includes)

include_directories(${SDL2_INCLUDE_DIRS}
					${SDL2_IMAGE_INCLUDE_DIRS}
					${SDL2_MIXER_INCLUDE_DIRS}
					${SDL2_TTF_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}	${SDL2_LIBRARIES}
										${SDL2_IMAGE_LIBRARIES}
										${SDL2_MIXER_LIBRARIES}
										${SDL2_TTF_LIBRARIES})
