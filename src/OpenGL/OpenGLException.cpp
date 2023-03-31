#include "OpenGLException.hpp"

namespace OpenGL
{

OpenGLException::OpenGLException(const char *message)
    : std::runtime_error{message}
{
}

OpenGLException::OpenGLException(const std::string &message)
    : std::runtime_error{message.c_str()}
{
}

} // namespace OpenGL
