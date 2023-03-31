cmake_minimum_required(VERSION 3.3.0)

set(${PROJECT_NAME}_EXECUTABLE_NAME ${PROJECT_NAME})

include(${${PROJECT_NAME}_MODULE_DIR}/CompilerOptions.cmake)

set(${PROJECT_NAME}_HEADER_CODE
    Model/Mesh.hpp
    Model/TextureFactory.hpp
    OpenGLWindow.hpp
    OpenGL/Detail/Set.hpp
    OpenGL/OpenGLBufferObject.hpp
    OpenGL/OpenGLException.hpp
    OpenGL/OpenGLShader.hpp
    OpenGL/OpenGLShaderProgram.hpp
    OpenGL/OpenGLVertexArrayObject.hpp
    OpenGL/OpenGLTexture.hpp
    Utils/Compilers.hpp
    Utils/Global.hpp
    Utils/StringFormat/StringFormat.hpp
    Utils/FileIO/Detail/Generals.hpp
    Utils/FileIO/FileIn.hpp
)

set(${PROJECT_NAME}_INLINE_CODE
    OpenGL/Detail/Set-inl.hpp
    OpenGL/OpenGLShaderProgram-inl.hpp
    Utils/StringFormat/StringFormat-inl.hpp
)

set(${PROJECT_NAME}_SOURCE_CODE
    Main.cpp
    Model/Mesh.cpp
    Model/TextureFactory.cpp
    OpenGLWindow.cpp
    OpenGL/OpenGLBufferObject.cpp
    OpenGL/OpenGLException.cpp
    OpenGL/OpenGLShader.cpp
    OpenGL/OpenGLShaderProgram.cpp
    OpenGL/OpenGLVertexArrayObject.cpp
    OpenGL/OpenGLTexture.cpp
    Utils/FileIO/Detail/Generals.cpp
    Utils/FileIO/FileIn.cpp
)

add_executable(${${PROJECT_NAME}_EXECUTABLE_NAME}
    ${${PROJECT_NAME}_HEADER_CODE}
    ${${PROJECT_NAME}_INLINE_CODE}
    ${${PROJECT_NAME}_SOURCE_CODE}
)

set_target_properties(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
)

target_include_directories(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${GLM_INCLUDE_DIRS}
        ${IMGUI_INCLUDE_DIRS}
        ${TINYOBJLOADER_INCLUDE_DIRS}
        ${STB_INCLUDE_DIRS}
)

target_compile_features(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        cxx_std_11
)

target_compile_options(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PUBLIC
        "$<$<CONFIG:DEBUG>:${${PROJECT_NAME}_CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:RELEASE>:${${PROJECT_NAME}_CXX_FLAGS_RELEASE}>"
)

target_compile_definitions(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PRIVATE
        GLM_FORCE_SILENT_WARNINGS
)

target_link_libraries(${${PROJECT_NAME}_EXECUTABLE_NAME}
    PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad
        glfw
        imgui
        stb
        tinyobjloader
        $<$<PLATFORM_ID:Linux>:${CMAKE_DL_LIBS}>
)

include(${${PROJECT_NAME}_MODULE_DIR}/PostBuildCommand.cmake)
