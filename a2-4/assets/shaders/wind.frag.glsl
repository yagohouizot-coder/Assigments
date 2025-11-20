#version 410 core

uniform sampler2D screen_texture;
uniform float screen_darkness;
uniform float time;

layout (location = 0) in vec2 frag_uv;
layout (location = 0) out vec4 color;

vec2 distort(vec2 uv, float t) {
	// (A2) Implement the wind distortion effect here. (You may want to use `sin`/`cos`)
	float border = min(min(uv.x, 1.0 - uv.x), min(uv.y, 1.0 - uv.y));
	border = smoothstep(0.0, 0.1, border); // Function to make a better transition with the values near the edges
	
	float wave = sin(uv.y * 5.0 + t);
	uv.x += wave * 0.025 * border; // Reduce distortion near borders, so its not seen on the other side
	
	return uv;
}

vec3 colorShift(vec3 in_color) {
	// (A2) Implement the shift in color here. (You may want to make it blue-ish)
	in_color.x *= 1;
	in_color.y *= 1;
	in_color.z *= 1,2; // We increment blue by 20%

	return in_color;
}

void main() {
	vec2 uv = distort(frag_uv, time);
	color = texture(screen_texture, uv);
	color.xyz = colorShift(color.xyz);
	color.xyz = screen_darkness * color.xyz;
}
