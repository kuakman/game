cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(BASE_DIR src/com/nahuelio)

file(GLOB_RECURSE SOURCE_CPP ${BASE_DIR}/game/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_CPP} src/com/nahuelio/game/headers/main.h src/com/nahuelio/game/controller/MainController.cpp src/com/nahuelio/game/controller/headers/MainController.h)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost ${BOOST_MIN_VERSION} REQUIRED)
if(NOT Boost_FOUND)
    message("Boost not found")
endif(NOT Boost_FOUND)

#### OpenGL
find_package(OpenGL REQUIRED)
if(NOT OpenGL_FOUND)
    message("OPENGL not found")
endif(NOT OpenGL_FOUND)

include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

#### GLFW
find_package(GLFW3 3.2 REQUIRED)
if(NOT GLFW3_FOUND)
    message("GLFW3 not found")
endif(NOT GLFW3_FOUND)

include_directories(${GLFW3_INCLUDE_DIRS})
link_directories(${GLFW3_LIBRARY_DIRS})
add_definitions(${GLFW3_DEFINITIONS})

#### GLAD & GLM
include_directories(${BASE_DIR}/libs/glad/include ${BASE_DIR}/libs/glm)


#### Target
target_include_directories(${PROJECT_NAME} PUBLIC ${OpenGL_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenGL_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLFW3_LIBRARY_DIRS})