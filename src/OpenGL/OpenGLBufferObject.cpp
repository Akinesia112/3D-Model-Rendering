#include "OpenGLBufferObject.hpp"

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

OpenGLBufferObject::OpenGLBufferObject(
    OpenGLBufferObject::Type type,
    OpenGLBufferObject::UsagePattern usagePattern)
    : id_{Detail::noId}, type_{type}, usagePattern_{usagePattern}
{
    create();
}

OpenGLBufferObject::OpenGLBufferObject(OpenGLBufferObject &&other) noexcept
    : id_{std::move(other.id_)}, type_{std::move(other.type_)},
      usagePattern_{std::move(other.usagePattern_)}
{
    other.id_ = Detail::noId; // Avoid double deletion
}

OpenGLBufferObject &
OpenGLBufferObject::operator=(OpenGLBufferObject &&other) noexcept
{
    if (this != &other)
    {
        if (Detail::isCreated(id_))
        {
            tidy();
        }

        id_ = std::move(other.id_);
        type_ = std::move(other.type_);
        usagePattern_ = std::move(other.usagePattern_);

        other.id_ = Detail::noId; // Avoid double deletion
    }

    return *this;
}

OpenGLBufferObject::~OpenGLBufferObject()
{
    if (Detail::isCreated(id_))
    {
        tidy();
    }
}

void OpenGLBufferObject::allocateBufferData(const void *data,
                                            GLsizeiptr size) noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    glBufferData(type_, size, data,usagePattern_);
}

void OpenGLBufferObject::bind() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    glBindBuffer(type_, id_);
}

void OpenGLBufferObject::create()
{
    PROGRAM_ASSERT(!Detail::isCreated(id_));

    glGenBuffers(1, &id_);

    if (!Detail::isCreated(id_))
    {
        throw OpenGLException("OpenGLBufferObject failed to instantiate.");
    }
}

GLuint OpenGLBufferObject::id() const noexcept { return id_; }

void OpenGLBufferObject::release() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    glBindBuffer(type_, 0);
}

void OpenGLBufferObject::tidy() noexcept
{
    PROGRAM_ASSERT(Detail::isCreated(id_));

    glDeleteBuffers(1, &id_);

    id_ = Detail::noId;
}

} // namespace OpenGL
