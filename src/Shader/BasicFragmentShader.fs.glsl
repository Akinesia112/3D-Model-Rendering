#version 330 core

out vec4 fragColor;

in VertexToFragment
{
    vec3 worldPosition;
    vec3 normal;
    vec2 textureCoordinate;
}
vertexToFragment;

uniform sampler2D objectTexture;

void main()
{
    fragColor = texture(objectTexture, vertexToFragment.textureCoordinate);
}
