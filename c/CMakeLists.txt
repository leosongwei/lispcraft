add_library(lispcraft SHARED lispcraft.h gl.c windowlib.c)
target_link_libraries(lispcraft GL GLU GLEW glfw)

set(CMAKE_C_FLAGS "-O2")        ## Optimize
