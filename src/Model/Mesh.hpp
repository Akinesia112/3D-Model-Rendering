#ifndef HOMEWORK01_MODEL_MESH_HPP_
#define HOMEWORK01_MODEL_MESH_HPP_

#include "OpenGL/OpenGLBufferObject.hpp"
#include "OpenGL/OpenGLShaderProgram.hpp"
#include "OpenGL/OpenGLTexture.hpp"
#include "OpenGL/OpenGLVertexArrayObject.hpp"

#include "glm/mat4x4.hpp"

#include <array>
#include <memory>
#include <vector>

namespace Model
{

class Mesh
{
public:
    using IndexType = unsigned int;
    using TextureType = OpenGL::OpenGLTexture;
    using ShaderProgramType = OpenGL::OpenGLShaderProgram;

    explicit Mesh() noexcept;
    explicit Mesh(const std::vector<float> &positions,
                  const std::vector<float> &normals,
                  const std::vector<float> &textureCoordinates,
                  const std::vector<IndexType> &indices,
                  ShaderProgramType &shaderProgram,
                  TextureType *texture = nullptr);

    Mesh(Mesh &&other) noexcept;
    Mesh &operator=(Mesh &&other) noexcept;
    ~Mesh();

    Mesh(const Mesh &other) = delete;
    Mesh &operator=(const Mesh &other) = delete;

    void draw(glm::mat4 &view, glm::mat4 &projection);

    glm::mat4 model();
    void setModel(glm::mat4 &model);

private:
    using VertexArrayObjectType = OpenGL::OpenGLVertexArrayObject;
    using BufferObjectType = OpenGL::OpenGLBufferObject;

    void create(const std::vector<float> &positions,
                const std::vector<float> &normals,
                const std::vector<float> &textureCoordinates,
                const std::vector<IndexType> &indices);
    void tidy() noexcept;

    static void vertexBufferObjectSetup(BufferObjectType &object,
                                        const std::vector<float> &data,
                                        ShaderProgramType &program,
                                        GLuint index, GLint size, GLenum type,
                                        GLboolean normalized, GLsizei stride,
                                        int offset);

    ShaderProgramType *shaderProgram_;
    TextureType *texture_;

    std::unique_ptr<VertexArrayObjectType> vertexArrayObject_;
    std::array<std::unique_ptr<BufferObjectType>, 3> vertexBufferObject_;
    std::unique_ptr<BufferObjectType> elementBufferObject_;

    GLsizei indicesCount_;

    glm::mat4 model_;
};

} // namespace Model

#endif // HOMEWORK01_MODEL_MESH_HPP_
