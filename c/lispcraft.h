#ifndef LIBLISPCRAFTC
#define LIBLISPCRAFTC

#include <stdio.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <sys/cdefs.h>
#include <stdlib.h>
int window_width, window_height;
GLFWwindow* main_window;

// window lib
void* init_glfw(int width, int height, const char* title);
int get_frame_size();

// gl utils
void establish_gl_context(void);
unsigned int build_shader(const char* vs_code, const char* fs_code);
void clear_buffers(void);
unsigned int make_texture(const char* c_texture_path);

#endif
