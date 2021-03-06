cmake_minimum_required(VERSION 3.9)
project(game)

# Notes to install dependencies on Mac OS Sierra:
# 1) git submodule update --init --recursive (Glad & GLM)
# 2) brew install glfw3
# 3) brew install boost
# 4) brew install qt5 --with-qtwebkit

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(BASE_DIR src/com/nahuelio)

message("\nCurrent Profile: " ${CMAKE_PROFILE})
message("Current Source Directory: " ${CMAKE_CURRENT_SOURCE_DIR})
message("Current Binary Directory: " ${CMAKE_CURRENT_BINARY_DIR}\n)

## Project Source & Headers
file(GLOB_RECURSE SOURCE_CPP ${BASE_DIR}/game/**/*.cpp ${BASE_DIR}/game/*.cpp)
file(GLOB_RECURSE SOURCE_H ${BASE_DIR}/game/**/*.h)

## GLAD & GLM Sources & Headers
get_filename_component(GLAD_INCLUDE_DIR ${BASE_DIR}/libs/glad/include ABSOLUTE)
get_filename_component(GLAD_SOURCE_DIR ${BASE_DIR}/libs/glad/src ABSOLUTE)
get_filename_component(GLM_DIR ${BASE_DIR}/libs/glm/glm ABSOLUTE)

#### Package Config
find_package(PkgConfig REQUIRED)

#### Boost
find_package(Boost 1.65.1 REQUIRED COMPONENTS system filesystem date_time iostreams)
if(Boost_FOUND)
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost Found")
else()
    message("Boost Not found")
endif(Boost_FOUND)

#### OpenGL
find_package(OpenGL 3.2 REQUIRED)
if(OPENGL_FOUND)
    message(STATUS "OPENGL Found")
    message(STATUS "    Includes - ${OPENGL_INCLUDE_DIR}")
    message(STATUS "    Libraries - ${OPENGL_LIBRARIES}")
else()
    message(STATUS "OPENGL Not Found")
endif(OPENGL_FOUND)

include_directories(${OPENGL_INCLUDE_DIR})
link_directories(${OPENGL_LIBRARIES})

#### GLFW
find_package(glfw3 3.2 REQUIRED)
if(glfw3_FOUND)
    message(STATUS "GLWF3 Found")
else()
    message("GLFW3 Not found")
endif(glfw3_FOUND)

#### QT5
find_package(Qt5 5.10.0 REQUIRED Core Widgets Gui Qml Quick Network)

#### QT5 Resources
file(GLOB_RECURSE Resources ${BASE_DIR}/**/*.qrc)
qt5_add_resources(ResourceSources ${Resources})

# FOR DEBUG
# get_cmake_property(_variableNames VARIABLES)
# foreach (_variableName ${_variableNames})
#   message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

#### GLAD & GLM
include_directories(${GLAD_INCLUDE_DIR} ${GLM_DIR})

### Assets
file(GLOB_RECURSE SHADERS ${BASE_DIR}/game/view/shaders/**/*.glsl ${BASE_DIR}/game/view/shaders/*.glsl)
message(STATUS "Assets | Shaders")
message(STATUS "    ${SHADERS}")
file(COPY ${SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders)

## Add All Sources & Headers
add_executable(${PROJECT_NAME} ${SOURCE_CPP} ${SOURCE_H}
        ${GLAD_INCLUDE_DIR}/glad/glad.h ${GLAD_INCLUDE_DIR}/KHR/khrplatform.h
        ${GLAD_SOURCE_DIR}/glad.c ${ResourceSources})

## QT5 Modules
qt5_use_modules(${PROJECT_NAME} Core Widgets Gui Qml Quick)

#### Target
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW3_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${OPENGL_LIBRARIES}
        glfw Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::Network)