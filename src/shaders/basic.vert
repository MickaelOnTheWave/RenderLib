#version 330 core
layout (location = 0) in vec3 aPos;

layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;

out vec3 objColor;
out vec2 texCoord;

uniform mat4 cameraTransform;
uniform mat4 objectTransform;
uniform vec3 objectColor;

void main()
{
   gl_Position = vec4(aPos, 1.0) * objectTransform * cameraTransform;
   objColor = objectColor;
   texCoord = aTex;
}
