#version 330 core

in vec3 fragPosition;
in vec3 normal;

out vec4 FragColor;

uniform vec3 lightPosition;
uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

    vec3 normalizedNormal = normalize(normal);
    vec3 lightVector = normalize(fragPosition - lightPosition);
    float diffuseStrength = max(dot(lightVector, normalizedNormal), 0);
    vec3 diffuse = diffuseStrength * lightColor;

    FragColor = vec4((ambient + diffuse) * objectColor, 1.0);
}
