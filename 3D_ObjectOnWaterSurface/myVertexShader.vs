#version 330

layout (location = 0) in vec3 vertexPosition;
in vec4 vertexColor

out vec4 fragColor; // test

void main()
{
    gl_Position = vec 4(vertexPosition.x, vertexPosition.y, vertexPosition.z, 1.0);

    fragColor = vertexColor(0.3, 0.5, 0.8, 1.0); // test
}