#include <stdio.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <sys/cdefs.h>
#include <stdlib.h>
#include "cpart.h"

/*
 * return status:
 *         0: good
 *         -1: not good
 *         other: err code
 */

void* init_glfw(int width, int height, const char* title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);

	window_width = width;
	window_height = height;

	glewExperimental = GL_TRUE;
	glewInit();

	main_window = window;
	return (void*)window;
}

int get_frame_size()
{
	glfwGetFramebufferSize(main_window, &window_width, &window_height);
	return 0;
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
