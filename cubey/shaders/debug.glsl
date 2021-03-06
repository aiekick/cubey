
__VS_UNLIT__

uniform mat4 u_mvp_mat;

layout(location = 0) in vec4 in_vertex_position;
layout(location = 1) in vec4 in_vertex_color;

out vec4 var_color;

void main() {
	gl_Position = u_mvp_mat * in_vertex_position;
	var_color = in_vertex_color;
}

__FS_UNLIT__

in vec4 var_color;

out vec4 out_color;

void main() {
	out_color = var_color;
}

__VS_LIT__

uniform mat4 u_mvp_mat;
uniform mat3 u_normal_mat;

layout(location = 0) in vec4 in_vertex_position;
layout(location = 1) in vec4 in_vertex_color;
layout(location = 2) in vec3 in_vertex_normal;

out vec4 var_color;
out vec3 var_normal;

void main() {
	gl_Position = u_mvp_mat * in_vertex_position;
	var_color = in_vertex_color;
	var_normal = normalize(u_normal_mat * in_vertex_normal);
}

__FS_LIT__

uniform vec3 u_ambient_light_color = vec3(0.5, 0.5, 0.5);
uniform vec3 u_directional_light_direction = vec3(-0.5f, -1.0f, -0.25f);
uniform vec3 u_directional_light_color = vec3(0.5f, 0.5f, 0.5f);

uniform mat4 u_view_mat;

in vec4 var_color;
in vec3 var_normal;

out vec4 out_color;

void main() {
	float diffuse = max(0.0, dot(var_normal, (u_view_mat * vec4(u_directional_light_direction, 0.0)).xyz));
	vec3 scattered_light = u_ambient_light_color + diffuse * u_directional_light_color;
	vec3 rgb = min(vec3(1.0), var_color.rgb * scattered_light);

	out_color = vec4(rgb, var_color.a);
}

