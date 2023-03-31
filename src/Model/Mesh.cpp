#include "Mesh.hpp"

#include "Utils/Global.hpp"

namespace Model
{

Mesh::Mesh() noexcept
    : shaderProgram_{nullptr}, texture_{nullptr}, vertexArrayObject_{nullptr},
      vertexBufferObject_{{nullptr, nullptr, nullptr}},
      elementBufferObject_{nullptr}, indicesCount_{0}, model_{1}
{
}

Mesh::Mesh(const std::vector<float> &positions,
           const std::vector<float> &normals,
           const std::vector<float> &textureCoordinates,
           const std::vector<IndexType> &indices,
           ShaderProgramType &shaderProgram, TextureType *texture)
    : shaderProgram_{&shaderProgram}, texture_{texture},
      vertexArrayObject_{nullptr}, vertexBufferObject_{{nullptr, nullptr,
                                                      nullptr}},
      elementBufferObject_{nullptr},
      indicesCount_{static_cast<GLsizei>(indices.size())}, model_{1}
{
    create(positions, normals, textureCoordinates, indices);
}

Mesh::Mesh(Mesh &&other) noexcept = default;

Mesh &Mesh::operator=(Mesh &&other) noexcept = default;

Mesh::~Mesh() noexcept { tidy(); }

void Mesh::vertexBufferObjectSetup(BufferObjectType &object,
                                   const std::vector<float> &data,
                                   ShaderProgramType &program, GLuint index,
                                   GLint size, GLenum type,
                                   GLboolean normalized, GLsizei stride,
                                   int offset)
{
    object.bind();
    object.allocateBufferData(data.data(), sizeof(float) * data.size());

    program.enableAttributeArray(index);
    program.mapAttributePointer(index, size, type, normalized, stride, offset);
}

void Mesh::create(const std::vector<float> &positions,
                  const std::vector<float> &normals,
                  const std::vector<float> &textureCoordinates,
                  const std::vector<IndexType> &indices)
{
    vertexArrayObject_.reset(new VertexArrayObjectType{});
    for (auto &object : vertexBufferObject_)
    {
        object.reset(new BufferObjectType{
            OpenGL::OpenGLBufferObject::Type::ArrayBuffer,
            OpenGL::OpenGLBufferObject::UsagePattern::StaticDraw});
    }
    elementBufferObject_.reset(new BufferObjectType{
        OpenGL::OpenGLBufferObject::Type::ElementArrayBuffer,
        OpenGL::OpenGLBufferObject::UsagePattern::StaticDraw});

    vertexArrayObject_->bind();

    vertexBufferObjectSetup(*(vertexBufferObject_[0]), positions,
                            *shaderProgram_, 0, 3, GL_FLOAT, GL_FALSE,
                            3 * sizeof(float), 0);

    vertexBufferObjectSetup(*(vertexBufferObject_[1]), normals, *shaderProgram_,
                            1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    vertexBufferObjectSetup(*(vertexBufferObject_[2]), textureCoordinates,
                            *shaderProgram_, 2, 2, GL_FLOAT, GL_FALSE,
                            2 * sizeof(float), 0);

    elementBufferObject_->bind();
    elementBufferObject_->allocateBufferData(indices.data(),
                                            sizeof(IndexType) * indices.size());

    vertexArrayObject_->release();
}

void Mesh::draw(glm::mat4 &view, glm::mat4 &projection)
{
    if (!(texture_))
    {
        glActiveTexture(GL_TEXTURE0);
        texture_->bind();
    }

    shaderProgram_->use();

    glm::mat4 mvp{projection * view * model_};

    shaderProgram_->setValue<4, 4>("mvp", mvp, false);

    vertexArrayObject_->bind();
    glDrawElements(GL_TRIANGLES, indicesCount_, GL_UNSIGNED_INT, 0);
    vertexArrayObject_->release();

    if (!(texture_))
    {
        glActiveTexture(GL_TEXTURE0);
    }
}

void Mesh::tidy() noexcept
{
    elementBufferObject_.reset();
    for (auto &object : vertexBufferObject_)
    {
        object.reset();
    }
    vertexArrayObject_.reset();
}

} // namespace Model
