#ifndef HOMEWORK01_OPENGL_BUFFEROBJECT_HPP_
#define HOMEWORK01_OPENGL_BUFFEROBJECT_HPP_

#include "glad/glad.h"

#include <memory>

namespace OpenGL
{

/**
 * \brief This class represents the OpenGL buffer object.
 *
 * \par Warning:
 * This class is not thread safe. Please use it under the same thread which
 * creates OpenGL content.
 */
class OpenGLBufferObject
{
public:
    /**
     *  \brief This enum represents the type of OpenGLBufferObject.
     */
    enum Type
    {
        /**
         * \brief Vertex buffer object
         */
        ArrayBuffer = GL_ARRAY_BUFFER,
        /**
         * \brief Index buffer object
         */
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER
    };

    /**
     *  \brief This enum represents the usage pattern of OpenGLBufferObject.
     */
    enum UsagePattern
    {
        /**
         * \brief Data will be modified once and used at most a few times for
         * drawing.
         */
        StreamDraw = GL_STREAM_DRAW,
        /**
         * \brief Data will be modified once and used at most a few times for
         * read data back to OpenGL server.
         */
        StreamRead = GL_STREAM_READ,
        /**
         * \brief Data will be modified once and used at most a few times for
         * read data back to OpenGL server and used in further drawing.
         */
        StreamCopy = GL_STREAM_COPY,
        /**
         * \brief Data will be modified once and used many times for drawing.
         */
        StaticDraw = GL_STATIC_DRAW,
        /**
         * \brief Data will be modified once and used many times for read data
         * back to OpenGL server.
         */
        StaticRead = GL_STATIC_READ,
        /**
         * \brief Data will be modified once and used many times for read data
         * back to OpenGL server and used in further drawing.
         */
        StaticCopy = GL_STATIC_COPY,
        /**
         * \brief Data will be modified many times and used many times for
         * drawing.
         */
        DynamicDraw = GL_DYNAMIC_DRAW,
        /**
         * \brief Data will be modified many times and used many times for read
         * data back to OpenGL server.
         */
        DynamicRead = GL_DYNAMIC_READ,
        /**
         * \brief Data will be modified many times and used many times for read
         * data back to OpenGL server and used in further drawing.
         */
        DynamicCopy = GL_DYNAMIC_COPY,
    };

    /**
     * \brief Initializes a new instance of the OpenGLBufferObject class with
     * specified \a type and \a usagePattern.
     *
     * \param type Specified OpenGLBufferObject::Type.
     * \param usagePattern Specified OpenGLBufferObject::UsagePattern.
     *
     * \exception OpenGLException Buffer failed to instantiate.
     */
    explicit OpenGLBufferObject(OpenGLBufferObject::Type type,
                                OpenGLBufferObject::UsagePattern usagePattern);

    /**
     * \brief Initializes a new instance of the OpenGLBufferObject class with
     * the content of \a other.
     *
     * \param other Another object to assign with.
     */
    OpenGLBufferObject(OpenGLBufferObject &&other) noexcept;
    /**
     * \brief Initializes a new instance of the OpenGLBufferObject class with
     * the content of \a other.
     *
     * \param other Another object to assign with.
     */
    OpenGLBufferObject &operator=(OpenGLBufferObject &&other) noexcept;
    /**
     * \brief Destroy the instance of the OpenGLBufferObject class.
     */
    ~OpenGLBufferObject();

    OpenGLBufferObject(const OpenGLBufferObject &other) = delete;
    OpenGLBufferObject &operator=(const OpenGLBufferObject &other) = delete;

    /**
     * \brief Allocate a new \a size bytes data storage for OpenGLBufferObject.
     * Initialize with \a data.
     *
     * \par Note:
     * \arg While allocating the new storage, any existing data in this buffer
     * is deleted.
     * \arg If data is \c nullptr, the data store is still created, but the
     * content is uninitialized and undefined.
     *
     * \param data A pointer to data which will copy into this buffer.
     * \param size Size of the data in bytes.
     */
    void allocateBufferData(const void *data, GLsizeiptr size) noexcept;

    /**
     * \brief Bind the OpenGLBufferObject to the current OpenGL content.
     *
     * \sa release
     */
    void bind() noexcept;
    /**
     * \brief Release the OpenGLBufferObject from the current OpenGL content.
     *
     * \par Note:
     * You don't need to call this function if you want to switch to another
     * OpenGLBufferObject. It will automatically release if another
     * OpenGLBufferObject is binding.
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
     * \brief Gets the id of the OpenGLBufferObject
     *
     * \return Specified id.
     */
    GLuint id() const noexcept;
    /**
     * \brief Gets the OpenGLBufferObject::Type of the OpenGLBufferObject.
     *
     * \return Specified OpenGLBufferObject::Type
     */
    OpenGLBufferObject::Type type() const;
    /**
     * \brief Gets the OpenGLBufferObject::UsagePattern of the
     * OpenGLBufferObject.
     *
     * \return Specified OpenGLBufferObject::UsagePattern
     */
    OpenGLBufferObject::UsagePattern usagePattern() const;

private:
    /**
     * \brief Create the buffer.
     *
     * \exception OpenGLException Buffer failed to instantiate.
     */
    void create();
    /**
     * \brief Clean up and delete the buffer.
     */
    void tidy() noexcept;

    /**
     * \brief The id of the OpenGLBufferObject.
     */
    GLuint id_;
    /**
     * \brief The OpenGLBufferObject::Type of the OpenGLBufferObject.
     */
    OpenGLBufferObject::Type type_;
    /**
     * \brief The OpenGLBufferObject::UsagePattern of the OpenGLBufferObject.
     */
    OpenGLBufferObject::UsagePattern usagePattern_;
};

} // namespace OpenGL

#endif // HOMEWORK01_OPENGL_BUFFEROBJECT_HPP_
