#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 fragPosition;
out vec3 normal;

uniform mat4 cameraTransform;
uniform mat4 objectTransform;

void main()
{
    vec4 pos4 = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    gl_Position = cameraTransform * objectTransform * pos4;
    fragPosition = vec3(objectTransform * pos4);
    normal = aNormal;
}
