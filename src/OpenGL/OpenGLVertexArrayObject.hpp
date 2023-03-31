#ifndef HOMEWORK01_OPENGL_OPENGLVERTEXARRAYOBJECT_HPP_
#define HOMEWORK01_OPENGL_OPENGLVERTEXARRAYOBJECT_HPP_

#include "glad/glad.h"

#include <memory>

namespace OpenGL
{

/**
 * \brief This class represents the OpenGL vertex array object.
 *
 * \par Warning:
 * This class is not thread safe. Please use it under the same thread which
 * creates OpenGL content.
 */
class OpenGLVertexArrayObject
{
public:
    /**
     * \brief Initializes a new instance of the OpenGL Vertex Array Object
     * class.
     *
     * \exception OpenGLException Buffer failed to instantiate.
     */
    explicit OpenGLVertexArrayObject();

    /**
     * \brief Initializes a new instance of the OpenGLVertexArrayObject class
     * with the content of \a other.
     *
     * \param other Another object to assign with.
     */
    OpenGLVertexArrayObject(OpenGLVertexArrayObject &&other) noexcept;
    /**
     * \brief Initializes a new instance of the OpenGLVertexArrayObject class
     * with the content of \a other.
     *
     * \param other Another object to assign with.
     */
    OpenGLVertexArrayObject &
    operator=(OpenGLVertexArrayObject &&other) noexcept;
    /**
     * \brief Destroy the instance of the OpenGLVertexArrayObject class.
     */
    ~OpenGLVertexArrayObject();

    OpenGLVertexArrayObject(const OpenGLVertexArrayObject &other) = delete;
    OpenGLVertexArrayObject &
    operator=(const OpenGLVertexArrayObject &other) = delete;

    /**
     * \brief Bind the OpenGLVertexArrayObject to the current OpenGL content.
     *
     * \sa release
     */
    void bind() noexcept;
    /**
     * \brief Release the OpenGLVertexArrayObject from the current OpenGL
     * content.
     *
     * \par Note:
     * You don't need to call this function if you want to switch to another
     * OpenGLVertexArrayObject. It will automatically release if another
     * OpenGLVertexArrayObject is binding.
     * \code{.cpp}
     * bufferFoo.bind();
     * // bufferFoo.release(); No need to call this function
     * bufferBar.bind();
     * bufferBar.release();
     * \endcode
     *
     * \sa bind
     */
    void release() noexcept;

    /**
     * \brief Gets the id of the OpenGLVertexArrayObject
     *
     * \return Specified id.
     */
    GLuint id() const noexcept;

private:
    /**
     * \brief Create the buffer.
     * \exception OpenGLException Buffer failed to instantiate.
     */
    void create();
    /**
     * \brief Clean up and delete the buffer.
     */
    void tidy() noexcept;

    /**
     * \brief The id of the OpenGLVertexArrayObject.
     */
    GLuint id_;
};

} // namespace OpenGL

#endif // HOMEWORK01_OPENGL_OPENGLVERTEXARRAYOBJECT_HPP_
