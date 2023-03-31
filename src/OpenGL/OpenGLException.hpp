#ifndef HOMEWORK01_OPENGL_OPENGLEXCEPTION_HPP_
#define HOMEWORK01_OPENGL_OPENGLEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace OpenGL
{

/**
 * \brief This class represent the OpenGL Exception.
 *
 * This class is used for throwing an exception about OpenGL content. It is
 * derived from std::runtime_error.
 */
class OpenGLException : public std::runtime_error
{
public:
    /**
     * \brief Initializes a new instance of the OpenGL Exception class with
     * specified \a message.
     *
     * \param message specified exception message.
     */
    explicit OpenGLException(const char *message);
    /**
     * \overload
     *
     * \param message specified exception message.
     */
    explicit OpenGLException(const std::string &message);
};

} // namespace OpenGL

#endif // HOMEWORK01_OPENGL_OPENGLEXCEPTION_HPP_
