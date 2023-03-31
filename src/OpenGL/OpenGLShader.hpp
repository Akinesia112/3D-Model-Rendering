#ifndef HOMEWORK01_OPENGL_OPENGLSHADER_HPP_
#define HOMEWORK01_OPENGL_OPENGLSHADER_HPP_

#include "glad/glad.h"

#include <memory>

namespace OpenGL
{

/**
 * \brief This class represents the OpenGL shader.
 *
 * \details This class supports shaders written in OpenGL Shading
 * Language(GLSL).
 *
 * \par Warning:
 * This class is not thread safe. Please use it under the same thread which
 * creates OpenGL content.
 *
 * \sa OpenGLShaderProgram
 */
class OpenGLShader
{
public:
    /**
     * \brief This enum represents the type of OpenGLShader
     *
     */
    enum Type
    {
        /**
         * \brief Vertex Shader
         */
        Vertex = GL_VERTEX_SHADER,
        /**
         * \brief Fragment Shader
         */
        Fragment = GL_FRAGMENT_SHADER,
        /**
         * \brief Geometry Shader
         */
        Geometry = GL_GEOMETRY_SHADER
    };

    /**
     * \brief Initializes a new instance of the OpenGLShader class with
     * specified \a type.
     *
     * \param type Specified OpenGLShader::Type.
     *
     * \exception OpenGLException Shader failed to instantiate.
     */
    explicit OpenGLShader(OpenGLShader::Type type);

    /**
     * \brief Initializes a new instance of the OpenGLShader class with the
     * content of \a other.
     *
     * \param other Another object to assign with.
     */
    OpenGLShader(OpenGLShader &&other) noexcept;
    /**
     * \brief Initializes a new instance of the OpenGLBufferObject class with
     * the content of \a other.
     *
     * \param other Another object to assign with.
     */
    OpenGLShader &operator=(OpenGLShader &&other) noexcept;
    /**
     * \brief Destroy the instance of the OpenGLShader class.
     */
    ~OpenGLShader();

    OpenGLShader(const OpenGLShader &other) = delete;
    OpenGLShader &operator=(const OpenGLShader &other) = delete;

    /**
     * \brief Get the source code of the \a fileName and compile it to
     * OpenGLShader.
     *
     * \param fileName File name of the source code.
     * \return Return \c true If the shader is compile successfully. Otherwise
     * return \c false.
     *
     * \sa OpenGLShader::compileFromSource
     */
    bool compileFromFile(const char *fileName) noexcept;
    /**
     * \brief Compile the \a source content into OpenGLShader.
     *
     * \param source Source code content.
     * \return Return \c true If the shader is compile successfully. Otherwise
     * return \c false.
     *
     * \sa OpenGLShader::compileFromFile
     */
    bool compileFromSource(const char *source) noexcept;

    /**
     * \brief Gets the id of the OpenGLShader
     *
     * \return Specified id.
     */
    GLuint id() const noexcept;
    /**
     * \brief Gets the OpenGLShader::Type of the OpenGLShader.
     *
     * \return Specified OpenGLShader::Type
     */
    OpenGLShader::Type type() const noexcept;

private:
    /**
     * \brief Create the shader.
     * \exception OpenGLException Shader failed to instantiate.
     */
    void create();
    /**
     * \brief Clean up and delete the shader.
     */
    void tidy() noexcept;

    /**
     * \brief Get the compile status.
     *
     * \return Return \c true If the shader is compile successfully. Otherwise
     * return \c false.
     */
    bool compileStatus() const noexcept;

    /**
     * \brief The id of the OpenGLShader.
     */
    GLuint id_;
    /**
     * \brief The OpenGLShader::Type of the OpenGLShader.
     */
    OpenGLShader::Type type_;
};

} // namespace OpenGL

#endif // HOMEWORK01_OPENGL_SHADER_HPP_
