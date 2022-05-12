#version 330

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;

out vec4 color;

void main()
{
    gl_Position = vec4(vertexPosition.x, vertexPosition.y, vertexPosition.z, 1.0);

    color = vec4(0.1f, 0.1f, 0.1f, 1.0f);
}