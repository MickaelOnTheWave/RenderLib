#version 330 core
out vec4 FragColor;
in vec3 color;
in vec2 texCoord;

uniform int textureCount;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    vec4 textureColor = texture(texture1, texCoord);
    if (textureCount > 1)
        textureColor += texture(texture2, texCoord);
    FragColor = textureColor * vec4(color, 1.0f);
}
