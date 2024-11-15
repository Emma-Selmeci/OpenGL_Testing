fragment
#version 450 core
in vec2 TexCoord;
out vec4 color;
uniform sampler2D tex;
void main()
{
	color = texture(tex, TexCoord);
	//color = vec4(1.0, 1.0, 1.0, 1.0);
}