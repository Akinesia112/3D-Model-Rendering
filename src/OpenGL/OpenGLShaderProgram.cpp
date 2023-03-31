#include "OpenGLShaderProgram.hpp"

#include "OpenGLException.hpp"

#include "Utils/Global.hpp"

#include <iostream>

namespace OpenGL
{

namespace Detail
{

constexpr GLuint noId{0};

bool isCreated(GLuint id) noexcept;
std::unique_ptr<OpenGLShader> makeShader(OpenGLShader::Type type);

inline bool isCreated(GLuint id) noexcept { return static_cast<bool>(id); }

std::unique_ptr<OpenGLShader> makeShader(OpenGLShader::Type type)
{
    std::unique_ptr<OpenGLShader> shader{nullptr};

    try
    {
        shader.reset(new OpenGLShader{type});
    }
    catch (OpenGLException &e)
    {

        std::cerr << "[Error]" << e.what();

        return std::unique_ptr<OpenGLShader>{nullptr};
    }

    return shader;
}

} // namespace Detail

OpenGLShaderProgram::OpenGLShaderProgram() : id_{Detail::noId} { create(); }

OpenGLShaderProgram::OpenGLShaderProgram(OpenGLShaderProgram &&other) noexcept
    : id_{std::move(other.id_)}
{
    other.id_ = 0; // Avoid double deletion
}

OpenGLShaderProgram &
OpenGLShaderProgram::operator=(OpenGLShaderProgram &&other) noexcept
{
    if (this != &other)
    {
        if (Detail::isCreated(id_))
        {
            tidy();
        }

        id_ = std::move(other.id_);
        shaders_ = std::move(other.shaders_);

        other.id_ = Detail::noId; // Avoid double deletion
    }

    return *this;
}

OpenGLShaderProgram::~OpenGLShaderProgram()
{
    if (Detail::isCreated(id_))
    {
        tidy();
    }
}

bool OpenGLShaderProgram::addShaderFromFile(OpenGLShader::Type type,
                                            const char *fileName) noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    auto shader = Detail::makeShader(type);

    if (!(shader.get()))
    {
        return false;
    }

    if (!shader->compileFromFile(fileName))
    {
        return false;
    }

    attachShader(std::move(shader));

    return true;
}

bool OpenGLShaderProgram::addShaderFromSource(OpenGLShader::Type type,
                                              const char *source) noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    auto shader = Detail::makeShader(type);

    if (!(shader.get()))
    {
        return false;
    }

    if (!shader->compileFromSource(source))
    {
        return false;
    }

    attachShader(std::move(shader));

    return true;
}

void OpenGLShaderProgram::attachShader(
    std::unique_ptr<OpenGLShader> &&shader) noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));
    // Fill in the Blank
    glAttachShader(id_, shader->id());
    shaders_.push_back(std::move(shader));
}

void OpenGLShaderProgram::create()
{
    PROGRAM_ASSERT(!Detail::isCreated(id_));
    // Fill in the Blank
    id_ = glCreateProgram();

    if (!Detail::isCreated(id_))
    {
        throw OpenGLException("OpenGLShaderProgram failed to instantiate.");
    }
}

void OpenGLShaderProgram::destroyProgram() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    // Fill in the Blank
    glDeleteProgram(id_);

    id_ = Detail::noId;
}

void OpenGLShaderProgram::destroyShaders() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    for (auto &shader : shaders_)
    {
        // Fill in the Blank
        glDeleteShader(shader->id());
        shader.reset(nullptr);
    }

    shaders_.clear();
}

void OpenGLShaderProgram::disableAttributeArray(GLuint index) noexcept
{
    // Fill in the Blank
    glDisableVertexAttribArray(index);
}

void OpenGLShaderProgram::enableAttributeArray(GLuint index) noexcept
{
    // Fill in the Blank
    glEnableVertexAttribArray(index);
}

GLuint OpenGLShaderProgram::id() const noexcept { return id_; }

void OpenGLShaderProgram::link() noexcept 
{ 
    // Fill in the Blank
    glLinkProgram(id_);
}

bool OpenGLShaderProgram::linkStatus() const noexcept
{
    GLint status;
    // Fill in the Blank
    glGetProgramiv(id_, GL_LINK_STATUS, &status);
    return (status == GL_TRUE);
}

void OpenGLShaderProgram::mapAttributePointer(GLuint index, GLint size,
                                              GLenum type, GLboolean normalized,
                                              GLsizei stride,
                                              int offset) noexcept
{
    // Fill in the Blank
    glVertexAttribPointer(index, size, type, normalized, stride,(GLvoid *)offset);
}

void OpenGLShaderProgram::tidy() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    destroyShaders();
    destroyProgram();
}

void OpenGLShaderProgram::use() noexcept 
{
    // Fill in the Blank
    glUseProgram(id_);
}

} // namespace OpenGL
