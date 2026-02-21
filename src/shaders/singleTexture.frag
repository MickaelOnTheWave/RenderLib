#version 330 core
out vec4 FragColor;
in vec2 texCoord;
in vec3 objColor;

uniform sampler2D colorTexture;

void main()
{
   //vec4 textureColor = texture(colorTexture, texCoord);
   vec4 textureColor = vec4(objColor, 1.0);
   FragColor = textureColor;
}
