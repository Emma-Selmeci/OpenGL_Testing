fragment
#version 450 core
in vec2 pos;
out vec4 color;
void main()
{
	float dist = distance(vec2(0.0), pos);
	dist = step(dist, 1.0);
	color = vec4(dist, dist, dist, 1.0);
}