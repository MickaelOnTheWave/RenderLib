#version 330 core

in vec3 fragPosition;
in vec3 normal;
in vec2 texCoord;

out vec4 FragColor;

uniform mat4 cameraTransform;
uniform vec3 lightPosition;
uniform vec3 objectColor;
uniform vec3 lightColor;

uniform vec3 cameraPosition;

// Material properties
uniform sampler2D diffuseTexture;
uniform vec3 specularColor;
uniform float shininess;

void main()
{
    float ambientStrength = 0.2;

    vec3 normalizedNormal = normalize(normal);
    vec3 lightVector = normalize(lightPosition - fragPosition);
    float diffuseStrength = max(dot(lightVector, normalizedNormal), 0);
    vec4 diffuseColor = texture(diffuseTexture, texCoord);
    vec4 diffuse = diffuseStrength * diffuseColor;

    vec4 ambient = ambientStrength * diffuseColor;

    //vec3 cameraPosition = vec3(cameraTransform[3][0], cameraTransform[3][1], cameraTransform[3][2]);
    //vec3 cameraPosition = vec3(cameraTransform[0][3], cameraTransform[1][3], cameraTransform[2][3]);

    float specularStrength = 0.8;
    vec3 viewDir = normalize(cameraPosition - fragPosition);
    vec3 reflectDir = reflect(-lightVector, normalizedNormal);
    int shininess = 128;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec4 specular = vec4(specularStrength * spec * specularColor, 1.0);

    FragColor = (ambient + diffuse + specular) * vec4(lightColor, 1.0);
}
