#include "OpenGLWindow.hpp"

#include "glm/vec2.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[])
{
    if (argc <= 4)
    {
        std::cerr << "Not enough parameter\n";
        std::cerr << "Expect: " << argv[0]
                  << "[model name] [texture name] [vertex shader file name] "
                     "[fragment shader file name]"
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string model{argv[1]};
    std::string texture{argv[2]};
    std::string vertexShader{argv[3]};
    std::string fragmentShader{argv[4]};

    std::cout << "Vertex Shader: " << vertexShader << "\n"
              << "Fragment Shader: " << fragmentShader << "\n"
              << "Model: " << model << "\n"
              << "Texture: " << texture << std::endl;

    std::unique_ptr<OpenGLWindow> window{nullptr};

    try
    {
        window.reset(new OpenGLWindow{glm::ivec2{800, 600}, "Homework01",
                                      glm::ivec2{3, 3}});
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    OpenGL::OpenGLShaderProgram *shaderProgram{window->addShader(
        vertexShader.c_str(), fragmentShader.c_str(), nullptr)};

    if (!shaderProgram)
    {
        std::cerr << "Failed to compile shader" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!window->addModel(model.c_str(), texture.c_str(), *shaderProgram))
    {
        std::cerr << "Failed to add model" << std::endl;
        exit(EXIT_FAILURE);
    }

    window->startRender();

    return 0;
}
