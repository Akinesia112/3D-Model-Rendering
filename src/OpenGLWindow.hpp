#ifndef HOMEWORK01_WINDOW_HPP_
#define HOMEWORK01_WINDOW_HPP_

#include "Model/Mesh.hpp"
#include "OpenGL/OpenGLShaderProgram.hpp"
#include "OpenGL/OpenGLTexture.hpp"

#include "glad/glad.h"

#include "GLFW/glfw3.h"

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

#include <memory>
#include <string>

class OpenGLWindow
{
private:
    enum RenderMode
    {
        Line = 0,
        Fill = 1
    };

public:
    explicit OpenGLWindow(glm::ivec2 windowSize, std::string title,
                          glm::ivec2 openglVersion);
    ~OpenGLWindow();

    OpenGLWindow(OpenGLWindow &&other) = delete;
    OpenGLWindow &operator=(OpenGLWindow &&other) = delete;
    OpenGLWindow(const OpenGLWindow &other) = delete;
    OpenGLWindow &operator=(const OpenGLWindow &other) = delete;

    void create();
    void startRender();

    bool addModel(const char *modelSource, const char *textureSource,
                  OpenGL::OpenGLShaderProgram &program);
    OpenGL::OpenGLShaderProgram *
    addShader(const char *vertexShaderSource, const char *fragmentShaderSource,
              const char *geometryShaderSource = nullptr);

private:
    bool createWindow();
    bool initializeGLAD();
    void initializeImgui();
    bool initializeOpenGL();

    void destroy();
    void destroyGLAD();
    void destroyImgui();
    void destroyOpenGL();

    void windowRenderLoop();
    void windowRenderUpdate();
    void windowRenderLateUpdate();
    void windowRenderImguiUpdate();

    void windowImguiGeneralSetting();

    void clearColor();

    void processInput();
    void shouldExit();
    void shouldShowPolygonMode();

    float aspectRatio() const noexcept;
    int height() const noexcept;
    int width() const noexcept;

    GLFWwindow *window_;

    glm::ivec2 size_;
    std::string title_;
    glm::ivec2 version_;

    std::vector<std::unique_ptr<Model::Mesh>> models_;
    std::vector<std::unique_ptr<OpenGL::OpenGLTexture>> textures;
    std::vector<std::unique_ptr<OpenGL::OpenGLShaderProgram>> shaders_;

    RenderMode renderMode_;

    glm::vec4 backgroundColor_;

    glm::vec3 lookAt_;
    glm::vec3 cameraPosition_;
};

#endif // HOMEWORK01_WINDOW_HPP_
