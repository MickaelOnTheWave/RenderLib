#version 330 core
out vec4 FragColor;
in vec2 texCoord;

uniform sampler2D colorTexture;

void main()
{
    //vec4 textureColor = texture(colorTexture, texCoord);
    //FragColor = textureColor;
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
