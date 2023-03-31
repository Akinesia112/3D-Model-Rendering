#include "OpenGLVertexArrayObject.hpp"

#include "OpenGLException.hpp"

#include "Utils/Global.hpp"

namespace OpenGL
{

namespace Detail
{

constexpr GLuint noId{0};

bool isCreated(GLuint id) noexcept;

inline bool isCreated(GLuint id) noexcept { return static_cast<bool>(id); }

} // namespace Detail

OpenGLVertexArrayObject::OpenGLVertexArrayObject() : id_{Detail::noId}
{
    create();
}

OpenGLVertexArrayObject::OpenGLVertexArrayObject(
    OpenGLVertexArrayObject &&other) noexcept
    : id_{std::move(other.id_)}
{
    other.id_ = 0; // Avoid double deletion
}

OpenGLVertexArrayObject &
OpenGLVertexArrayObject::operator=(OpenGLVertexArrayObject &&other) noexcept
{
    if (this != &other)
    {
        if (Detail::isCreated(id_))
        {
            tidy();
        }

        id_ = std::move(other.id_);

        other.id_ = Detail::noId; // Avoid double deletion
    }

    return *this;
}

OpenGLVertexArrayObject::~OpenGLVertexArrayObject()
{
    if (Detail::isCreated(id_))
    {
        tidy();
    }
}

void OpenGLVertexArrayObject::bind() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    // Fill in the Blank
    glBindVertexArray(id_);
}

GLuint OpenGLVertexArrayObject::id() const noexcept { return id_; }

void OpenGLVertexArrayObject::release() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(0));

    // Fill in the Blank
    // Unbind the currently bound VAO
    glBindVertexArray(0);


}

void OpenGLVertexArrayObject::create()
{
    PROGRAM_ASSERT(!Detail::isCreated(id_));

    // Fill in the Blank
    glGenVertexArrays(1, &id_);

    if (!Detail::isCreated(id_))
    {
        throw OpenGLException("OpenGLVertexArrayObject failed to instantiate.");
    }
}

void OpenGLVertexArrayObject::tidy() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    // Fill in the Blank
    glDeleteVertexArrays(1, &id_);

    id_ = Detail::noId;
}

} // namespace OpenGL
