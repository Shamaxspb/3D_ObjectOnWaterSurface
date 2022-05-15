#version 330

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;

out vec4 color;

uniform mat4 transform;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = transform * vec4(vertexPosition, 1.0f);
    //gl_Position = projection * view * model * vec4(vertexPosition, 1.0);
    //gl_Position = vec4(vertexPosition.x, vertexPosition.y, vertexPosition.z, 1.0);

    color = vec4(0.8, 0.5, 0.3, 1.0);
}