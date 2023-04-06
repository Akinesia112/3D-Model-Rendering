#include "OpenGLShader.hpp"

#include "OpenGLException.hpp"

#include "Utils/FileIO/FileIn.hpp"
#include "Utils/Global.hpp"

#include <cstring>

#include <string>

namespace OpenGL
{

namespace Detail
{

constexpr GLuint noId{0};

bool compileStatus(GLuint id) noexcept;
bool isCreated(GLuint id) noexcept;

inline bool compileStatus(GLuint id) noexcept
{
    GLint status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    return (status == GL_TRUE);
}

inline bool isCreated(GLuint id) noexcept { return static_cast<bool>(id); }

} // namespace Detail

OpenGLShader::OpenGLShader(OpenGLShader::Type type)
    : id_{Detail::noId}, type_{type}
{
    create();
}

OpenGLShader::OpenGLShader(OpenGLShader &&other) noexcept
    : id_{std::move(other.id_)}, type_{std::move(other.type_)}
{
    other.id_ = Detail::noId; // Avoid double deletion
}

OpenGLShader &OpenGLShader::operator=(OpenGLShader &&other) noexcept
{
    if (this != &other)
    {
        if (Detail::isCreated(id_))
        {
            tidy();
        }

        id_ = std::move(other.id_);
        type_ = std::move(other.type_);

        other.id_ = Detail::noId; // Avoid double deletion
    }

    return *this;
}

OpenGLShader::~OpenGLShader()
{
    if (Detail::isCreated(id_))
    {
        tidy();
    }
}

bool OpenGLShader::compileFromFile(const char *fileName) noexcept
{
    std::string source{FileIO::ReadFileFullText(fileName)};

    return compileFromSource(source.c_str());
}

bool OpenGLShader::compileFromSource(const char *source) noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));
    glShaderSource(id_, 1, &source, NULL);
    glCompileShader(id_);


    return Detail::compileStatus(id_);
}

void OpenGLShader::create()
{
    PROGRAM_ASSERT(!Detail::isCreated(id_));
    id_ = glCreateShader(type_);

    if (!Detail::isCreated(id_))
    {
        throw OpenGLException("OpenGLShader failed to instantiate.");
    }
}

GLuint OpenGLShader::id() const noexcept { return id_; }

void OpenGLShader::tidy() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));
    glDeleteShader(id_);
    id_ = Detail::noId;
}

OpenGLShader::Type OpenGLShader::type() const noexcept { return type_; }

} // namespace OpenGL
