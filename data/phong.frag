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
uniform sampler2D specularTexture;
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

    vec4 specular;
    float lightNormalDot = dot(normalizedNormal, lightVector);
    if (lightNormalDot > 0.0)
    {
        float specularStrength = 0.8;
        vec4 specularColor = texture(specularTexture, texCoord);
        vec3 viewDir = normalize(cameraPosition - fragPosition);
        vec3 reflectDir = reflect(-lightVector, normalizedNormal);
        int shininess = 128;
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
        specular = specularColor * specularStrength * spec;
    }

    FragColor = (ambient + diffuse + specular) * vec4(lightColor, 1.0);
}
