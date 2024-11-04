#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;

out vec3 color;
out vec2 texCoord;

uniform mat4 cameraTransform;
uniform mat4 objectTransform;

void main()
{
    gl_Position = cameraTransform * objectTransform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    color = aCol;
    texCoord = aTex;
}
