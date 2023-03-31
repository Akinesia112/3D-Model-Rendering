#ifndef HOMEWORK01_RENDER_DETAILS_SET_HPP_
#define HOMEWORK01_RENDER_DETAILS_SET_HPP_

#include "glm/detail/qualifier.hpp"

namespace OpenGL
{

namespace Detail
{

template <typename T>
struct SetValue
{
    static void inline execute(unsigned int id, const char *name,
                               T value) noexcept;
};

template <typename T>
struct SetVector2
{
    static void inline execute(unsigned int id, const char *name, T x,
                               T y) noexcept;
    static void inline execute(unsigned int id, const char *name,
                               const glm::vec<2, T> &vector) noexcept;
};

template <typename T>
struct SetVector3
{
    static void inline execute(unsigned int id, const char *name, T x, T y,
                               T z) noexcept;
    static void inline execute(unsigned int id, const char *name,
                               const glm::vec<3, T> &vector) noexcept;
};

template <typename T>
struct SetVector4
{
    static void inline execute(unsigned int id, const char *name, T x, T y, T z,
                               T w) noexcept;
    static void inline execute(unsigned int id, const char *name,
                               const glm::vec<4, T> &vector) noexcept;
};

template <int row, int column>
struct SetMatrix
{
    static void inline execute(
        unsigned int id, const char *name, bool transpose,
        const glm::mat<row, column, float> &matrix) noexcept;
};

} // namespace Detail

} // namespace OpenGL

#include "Set-inl.hpp"

#endif // HOMEWORK01_RENDER_DETAILS_SET_HPP_
