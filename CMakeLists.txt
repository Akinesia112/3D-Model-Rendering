cmake_minimum_required(VERSION 3.3.0)

project("Homework01"
        VERSION 1.0.0
        DESCRIPTION "Show the obj model with OpenGL")

set(${PROJECT_NAME}_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(${PROJECT_NAME}_MODULE_DIR "${CMAKE_SOURCE_DIR}/cmake")
set(${PROJECT_NAME}_THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/thirdparty")

find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(glm REQUIRED)
add_subdirectory("${${PROJECT_NAME}_THIRDPARTY_DIR}/glad")
add_subdirectory("${${PROJECT_NAME}_THIRDPARTY_DIR}/imgui")
add_subdirectory("${${PROJECT_NAME}_THIRDPARTY_DIR}/stb")
add_subdirectory("${${PROJECT_NAME}_THIRDPARTY_DIR}/tinyobjloader")

add_subdirectory(${${PROJECT_NAME}_SOURCE_DIR})
