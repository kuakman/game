cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(BASE_DIR src/com/nahuelio)

## Project Source & Headers
file(GLOB_RECURSE SOURCE_CPP ${BASE_DIR}/game/*.cpp)
file(GLOB_RECURSE SOURCE_H ${BASE_DIR}/game/**/*.h)

## GLAD & GLM Sources & Headers
get_filename_component(GLAD_INCLUDE_DIR ${BASE_DIR}/libs/glad/include/glad ABSOLUTE)
get_filename_component(GLAD_SOURCE_DIR ${BASE_DIR}/libs/glad/src ABSOLUTE)
get_filename_component(GLM_DIR ${BASE_DIR}/libs/glm/glm ABSOLUTE)

## Add All Sources & Headers
add_executable(${PROJECT_NAME} ${SOURCE_CPP} ${SOURCE_H} ${GLAD_INCLUDE_DIR}/glad.h ${GLAD_SOURCE_DIR}/glad.c)

#### Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(PkgConfig REQUIRED)

find_package(Boost 1.64 REQUIRED)
if(NOT Boost_FOUND)
    message("Boost not found")
endif(NOT Boost_FOUND)

#### OpenGL
find_package(OpenGL 3.2 REQUIRED)
if(OPENGL_FOUND)
    message(STATUS "OPENGL Found")
else()
    message(STATUS "OPENGL Not Found")
endif(OPENGL_FOUND)

include_directories(${OPENGL_INCLUDE_DIR})
link_directories(${OPENGL_LIBRARIES})

#### GLFW
pkg_search_module(GLFW3 REQUIRED glfw3)
if(GLFW3_FOUND)
    message(STATUS "GLWF3 Found")
else()
    message("GLFW3 Not found")
endif(GLFW3_FOUND)

include_directories(${GLFW3_INCLUDE_DIRS})
link_directories(${GLFW3_LIBRARY_DIRS})

#### GLAD & GLM
include_directories(${GLAD_INCLUDE_DIR} ${GLM_DIR})

#### Target
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW3_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLFW3_LIBRARIES})