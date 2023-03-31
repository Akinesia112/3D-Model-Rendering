#include "Detail/Set.hpp"

#include "glad/glad.h"

#include "glm/detail/qualifier.hpp"

#include <type_traits>

namespace OpenGL
{

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name,
                                          T value) const noexcept
{
    static_assert(std::is_same<T, bool>::value || std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept bool, int, unsigned int, and float type");

    Detail::SetValue<T>::execute(id(), name, value);
}

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name, T x,
                                          T y) const noexcept
{
    static_assert(std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept int, unsigned int, and float type");

    Detail::SetVector2<T>::execute(id(), name, x, y);
}

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name,
                                          glm::vec<2, T> vector) const noexcept
{
    static_assert(std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept int, unsigned int, and float type");

    Detail::SetVector2<T>::execute(id(), name, vector);
}

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name, T x, T y,
                                          T z) const noexcept
{
    static_assert(std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept int, unsigned int, and float type");

    Detail::SetVector3<T>::execute(id(), name, x, y, z);
}

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name,
                                          glm::vec<3, T> vector) const noexcept
{
    static_assert(std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept int, unsigned int, and float type");

    Detail::SetVector3<T>::execute(id(), name, vector);
}

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name, T x, T y, T z,
                                          T w) const noexcept
{
    static_assert(std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept int, unsigned int, and float type");

    Detail::SetVector4<T>::execute(id(), name, x, y, z, w);
}

template <typename T>
inline void OpenGLShaderProgram::setValue(const char *name,
                                          glm::vec<4, T> vector) const noexcept
{
    static_assert(std::is_same<T, int>::value ||
                      std::is_same<T, unsigned int>::value ||
                      std::is_same<T, float>::value,
                  "Only accept int, unsigned int, and float type");

    Detail::SetVector4<T>::execute(id(), name, vector);
}

template <int row, int column>
inline void OpenGLShaderProgram::setValue(const char *name,
                                          glm::mat<row, column, float> matrix,
                                          bool transpose) const noexcept
{
    static_assert(row > 1 && row <= 4,
                  "Row value of this matrix should be in range [2, 4]");
    static_assert(column > 1 && column <= 4,
                  "Column value of this matrix should be in range [2, 4]");
    Detail::SetMatrix<row, column>::execute(id(), name, transpose, matrix);
}

} // namespace OpenGL
