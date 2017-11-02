int window_width, window_height;
GLFWwindow* main_window;

void* init_glfw(int width, int height, const char* title);
int get_frame_size();
unsigned int build_shader(const char* vs_code, const char* fs_code);
