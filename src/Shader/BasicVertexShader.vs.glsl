#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 textureCoordinate;

out VertexToFragment
{
    vec3 worldPosition;
    vec3 normal;
    vec2 textureCoordinate;
}
vertexToFragment;

uniform mat4 mvp;

void main()
{
    vec4 pos = mvp * vec4(position, 1.0);

    vertexToFragment.worldPosition = pos.xyz;
    vertexToFragment.normal = normal;
    vertexToFragment.textureCoordinate = textureCoordinate;

    gl_Position = pos;
}
