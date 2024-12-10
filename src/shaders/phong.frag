#version 330 core

in vec3 fragPosition;
in vec3 normal;

out vec4 FragColor;

uniform mat4 cameraTransform;
uniform vec3 lightPosition;
uniform vec3 objectColor;
uniform vec3 lightColor;

// Material properties
uniform vec3 ambientColor;
uniform vec3 diffuseColor;
uniform vec3 specularColor;
uniform float shininess;

void main()
{
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * ambientColor;

    vec3 normalizedNormal = normalize(normal);
    vec3 lightVector = normalize(lightPosition - fragPosition);
    float diffuseStrength = max(dot(lightVector, normalizedNormal), 0);
    vec3 diffuse = diffuseStrength * diffuseColor;

    //vec3 cameraPosition = vec3(cameraTransform[3][0], cameraTransform[3][1], cameraTransform[3][2]);
    vec3 cameraPosition = vec3(cameraTransform[0][3], cameraTransform[1][3], cameraTransform[2][3]);

    float specularStrength = 0.8;
    vec3 viewDir = normalize(cameraPosition - fragPosition);
    vec3 reflectDir = reflect(-lightVector, normalizedNormal);
    int shininess = 128;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * specularColor;

    FragColor = vec4((ambient + diffuse + specular) * lightColor, 1.0);
}
