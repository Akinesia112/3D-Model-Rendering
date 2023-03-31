#include "glad/glad.h"

#include "glm/gtc/type_ptr.hpp"
#include "glm/mat2x2.hpp"
#include "glm/mat2x3.hpp"
#include "glm/mat2x4.hpp"
#include "glm/mat3x2.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat3x4.hpp"
#include "glm/mat4x2.hpp"
#include "glm/mat4x3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

namespace OpenGL
{

namespace Detail
{

namespace
{

GLboolean inline ToGlBoolean(bool x) noexcept;

GLboolean inline ToGlBoolean(bool x) noexcept
{
    return static_cast<GLboolean>(x ? GL_TRUE : GL_FALSE);
}

} // namespace

template <>
void inline SetValue<bool>::execute(unsigned int id, const char *name,
                                    bool value) noexcept
{
    glUniform1i(glGetUniformLocation(id, name), ToGlBoolean(value));
}

template <>
void inline SetValue<int>::execute(unsigned int id, const char *name,
                                   int value) noexcept
{
    glUniform1i(glGetUniformLocation(id, name), value);
}

template <>
void inline SetValue<unsigned int>::execute(unsigned int id, const char *name,
                                            unsigned int value) noexcept
{
    glUniform1ui(glGetUniformLocation(id, name), value);
}

template <>
void inline SetValue<float>::execute(unsigned int id, const char *name,
                                     float value) noexcept
{
    glUniform1f(glGetUniformLocation(id, name), value);
}

template <>
void inline SetVector2<int>::execute(unsigned int id, const char *name, int x,
                                     int y) noexcept
{
    glUniform2i(glGetUniformLocation(id, name), x, y);
}

template <>
void inline SetVector2<int>::execute(unsigned int id, const char *name,
                                     const glm::vec<2, int> &vector) noexcept
{
    glUniform2iv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector2<unsigned int>::execute(unsigned int id, const char *name,
                                              unsigned int x,
                                              unsigned int y) noexcept
{
    glUniform2ui(glGetUniformLocation(id, name), x, y);
}

template <>
void inline SetVector2<unsigned int>::execute(
    unsigned int id, const char *name,
    const glm::vec<2, unsigned int> &vector) noexcept
{
    glUniform2uiv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector2<float>::execute(unsigned int id, const char *name,
                                       float x, float y) noexcept
{
    glUniform2f(glGetUniformLocation(id, name), x, y);
}

template <>
void inline SetVector2<float>::execute(
    unsigned int id, const char *name,
    const glm::vec<2, float> &vector) noexcept
{
    glUniform2fv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector3<int>::execute(unsigned int id, const char *name, int x,
                                     int y, int z) noexcept
{
    glUniform3i(glGetUniformLocation(id, name), x, y, z);
}

template <>
void inline SetVector3<int>::execute(unsigned int id, const char *name,
                                     const glm::vec<3, int> &vector) noexcept
{
    glUniform3iv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector3<unsigned int>::execute(unsigned int id, const char *name,
                                              unsigned int x, unsigned int y,
                                              unsigned int z) noexcept
{
    glUniform3ui(glGetUniformLocation(id, name), x, y, z);
}

template <>
void inline SetVector3<unsigned int>::execute(
    unsigned int id, const char *name,
    const glm::vec<3, unsigned int> &vector) noexcept
{
    glUniform3uiv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector3<float>::execute(unsigned int id, const char *name,
                                       float x, float y, float z) noexcept
{
    glUniform3f(glGetUniformLocation(id, name), x, y, z);
}

template <>
void inline SetVector3<float>::execute(
    unsigned int id, const char *name,
    const glm::vec<3, float> &vector) noexcept
{
    glUniform3fv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector4<int>::execute(unsigned int id, const char *name, int x,
                                     int y, int z, int w) noexcept
{
    glUniform4i(glGetUniformLocation(id, name), x, y, z, w);
}

template <>
void inline SetVector4<int>::execute(unsigned int id, const char *name,
                                     const glm::vec<4, int> &vector) noexcept
{
    glUniform4iv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector4<unsigned int>::execute(unsigned int id, const char *name,
                                              unsigned int x, unsigned int y,
                                              unsigned int z,
                                              unsigned int w) noexcept
{
    glUniform4ui(glGetUniformLocation(id, name), x, y, z, w);
}

template <>
void inline SetVector4<unsigned int>::execute(
    unsigned int id, const char *name,
    const glm::vec<4, unsigned int> &vector) noexcept
{
    glUniform4uiv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetVector4<float>::execute(unsigned int id, const char *name,
                                       float x, float y, float z,
                                       float w) noexcept
{
    glUniform4f(glGetUniformLocation(id, name), x, y, z, w);
}

template <>
void inline SetVector4<float>::execute(
    unsigned int id, const char *name,
    const glm::vec<4, float> &vector) noexcept
{
    glUniform4fv(glGetUniformLocation(id, name), 1, &(vector[0]));
}

template <>
void inline SetMatrix<2, 2>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<2, 2, float> &matrix) noexcept
{
    glUniformMatrix2fv(glGetUniformLocation(id, name), 1,
                       ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<2, 3>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<2, 3, float> &matrix) noexcept
{
    glUniformMatrix2x3fv(glGetUniformLocation(id, name), 1,
                         ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<2, 4>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<2, 4, float> &matrix) noexcept
{
    glUniformMatrix2x4fv(glGetUniformLocation(id, name), 1,
                         ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<3, 2>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<3, 2, float> &matrix) noexcept
{
    glUniformMatrix3x2fv(glGetUniformLocation(id, name), 1,
                         ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<3, 3>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<3, 3, float> &matrix) noexcept
{
    glUniformMatrix3fv(glGetUniformLocation(id, name), 1,
                       ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<3, 4>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<3, 4, float> &matrix) noexcept
{
    glUniformMatrix3x4fv(glGetUniformLocation(id, name), 1,
                         ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<4, 2>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<4, 2, float> &matrix) noexcept
{
    glUniformMatrix4x2fv(glGetUniformLocation(id, name), 1,
                         ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<4, 3>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<4, 3, float> &matrix) noexcept
{
    glUniformMatrix4x3fv(glGetUniformLocation(id, name), 1,
                         ToGlBoolean(transpose), glm::value_ptr(matrix));
}

template <>
void inline SetMatrix<4, 4>::execute(
    unsigned int id, const char *name, bool transpose,
    const glm::mat<4, 4, float> &matrix) noexcept
{
    glUniformMatrix4fv(glGetUniformLocation(id, name), 1,
                       ToGlBoolean(transpose), glm::value_ptr(matrix));
}

} // namespace Detail

} // namespace OpenGL
