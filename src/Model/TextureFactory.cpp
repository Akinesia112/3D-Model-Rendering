#include "TextureFactory.hpp"

#include "Utils/Compilers.hpp"

PRAGMA_WARNING_PUSH
PRAGMA_WARNING_DISABLE_DOUBLEPROMOTION

#include "stb_image.h"

PRAGMA_WARNING_POP

namespace Model
{

namespace Detail
{

GLenum rgbFormat(int channels) noexcept;

GLenum rgbFormat(int channels) noexcept
{
    switch (channels)
    {
    case 1:
        return GL_RED;
    case 2:
        return GL_RG;
    case 4:
        return GL_RGBA;
    case 3:
    default:
        return GL_RGB;
    }
}

} // namespace Detail

std::unique_ptr<OpenGL::OpenGLTexture>
TextureFactory::loadFromFile(const char *fileName)
{
    int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data{stbi_load(fileName, &width, &height, &channels, 0)};

    if (!data)
    {
        return std::unique_ptr<OpenGL::OpenGLTexture>{
            new OpenGL::OpenGLTexture()};
    }

    const size_t size{static_cast<size_t>(width * height * channels)};

    std::vector<unsigned char> buffer{data, data + size};
    stbi_image_free(data);

    return std::unique_ptr<OpenGL::OpenGLTexture>{new OpenGL::OpenGLTexture{
        width, height, Detail::rgbFormat(channels), buffer}};
}

} // namespace Model
