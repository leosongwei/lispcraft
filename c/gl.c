#include "lispcraft.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void establish_gl_context(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.7f, 0.0f, 0.0f, 1.0f);
}

unsigned int build_shader(const char* vs_code, const char* fs_code)
{
	GLint success;
	GLint log_length;
	GLchar* info_log_buffer;
	// compile vertex shader
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vs_code, NULL);
	glCompileShader(vertex_shader);
	// check for compile errors
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &log_length);
		info_log_buffer = (GLchar*)malloc(sizeof(GLchar) * log_length);
		glGetShaderInfoLog(vertex_shader,
				log_length, NULL, info_log_buffer);
		printf("Vertex shader compile error:\n");
		printf("%s\n", info_log_buffer);
		free(info_log_buffer);
        return 0;
	}else{
		printf("Vertex shader compilation succeeded.\n");
	}

	// compile fragment shader
	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fs_code, NULL);
	glCompileShader(fragment_shader);
	// check for compile errors
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &log_length);
		info_log_buffer = (GLchar*)malloc(sizeof(GLchar) * log_length);
		glGetShaderInfoLog(fragment_shader,
				log_length, NULL, info_log_buffer);
		printf("Fragment shader compile error:\n");
		printf("%s\n", info_log_buffer);
		free(info_log_buffer);
        return 0;
	}else{
		printf("Fragment shader compilation succeeded.\n");
	}

	// link shaders
	GLuint shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);
	// check for linking errors
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramiv(shader_program, GL_INFO_LOG_LENGTH, &log_length);
		info_log_buffer = (GLchar*)malloc(sizeof(GLchar) * log_length);
		glGetProgramInfoLog(shader_program,
				log_length, NULL, info_log_buffer);
		printf("Shader program linking error:\n");
		printf("%s\n", info_log_buffer);
		free(info_log_buffer);
        return 0;
	}else{
		printf("Shader program linking succeeded.\n");
	}
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return (unsigned int)shader_program;
}

void clear_buffers(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

unsigned int make_texture(const char* c_texture_path)
{
	unsigned int texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	// clamp to border, makes debugging easier
	GLfloat v_bc[] = {1.0f,0.0f,1.0f,1.0f}; // pink
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, v_bc);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	int width, height, channels;
	void* picture_memory = (void*)stbi_load(c_texture_path, &width, &height, &channels, 0);

	if(picture_memory){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
				GL_RGB, GL_UNSIGNED_BYTE, (GLvoid *)picture_memory);
		glGenerateMipmap(GL_TEXTURE_2D);
	}else{
		printf("make_texture: textrue(\"%s\") loading failed!\n", c_texture_path);
		return 0;
	}
	stbi_image_free(picture_memory);

	glBindTexture(GL_TEXTURE_2D, 0);
	return texture_id;
}
