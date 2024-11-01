shadertype: vertex

#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texpos;
layout (location = 2) in float offsetparam;

out vec2 vertextexpos;

uniform vec2 offset;
uniform mat4 view;
uniform mat4 proj;

void main(void) {
	vertextexpos = texpos;
	gl_Position = proj * view * (vec4(position, 1.0) + offsetparam * vec4(offset.x, 0.0, offset.y, 0.0));
}