#ifndef HOMEWORK01_MODEL_VERTEX_HPP_
#define HOMEWORK01_MODEL_VERTEX_HPP_

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

namespace Model
{

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoordinate;
};

} // namespace Model

#endif // HOMEWORK01_MODEL_VERTEX_HPP_
