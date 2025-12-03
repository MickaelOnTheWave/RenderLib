#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTex;

out vec3 fragPosition;
out vec3 normal;
out vec2 texCoord;

uniform mat4 cameraProjection;
uniform mat4 cameraTransform;
uniform mat4 objectTransform;

void main()
{
    vec4 pos4 = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    gl_Position = cameraProjection * cameraTransform * objectTransform * pos4;
    fragPosition = vec3(objectTransform * pos4);
    normal = aNormal;
    texCoord = aTex;
}
