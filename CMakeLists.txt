cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(BASE_DIR src/com/nahuelio)

add_executable(${PROJECT_NAME} src/com/nahuelio/game/main.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

include_directories(${BASE_DIR}/libs,
        ${BASE_DIR}/libs/glad/include)

#target_include_directories(${PROJECT_NAME} ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${OPENGL_glu_LIBRARY})