#version 330

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_texcoords;

uniform mat4 model_matrix, view_matrix, projection_matrix;

out vec2 g_texcoords;

void main() {

	vec3 out_position = in_position;
    
	g_texcoords = in_texcoords.xy;
		
	gl_Position = projection_matrix * view_matrix * model_matrix * vec4(out_position, 1);
}
