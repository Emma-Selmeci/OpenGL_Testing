vertex
#version 450 core
layout (location = 0) in vec2 position;
out vec2 pos;
void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
    pos = vec2((position.x + 1.0) * 0.5, (position.y + 1.0) * 0.5);
}