(cffi:load-foreign-library #p"./c/liblispcraft.so")
;; ------------------------------------------------------------
;; GLFW
;; int glfwWindowShouldClose(GLFWwindow* window)
;; example: while(!glfwWindowShouldClose(window)){ render loop... }
(cffi:defcfun "glfwWindowShouldClose" :int (window :pointer))

;; void glfwTerminate(void)
;; example: glfwTerminate();
(cffi:defcfun "glfwTerminate" :void)

;; ------------------------------------------------------------
;; Window lib

;; void* init_glfw(int width, int height, const char* title);
(cffi:defcfun "init_glfw" :pointer
  (width :int) (height :int) (title :pointer))
;; void glfwSwapBuffers(GLFWwindow *window);
(cffi:defcfun "glfwSwapBuffers" :void (window :pointer))

;; ------------------------------------------------------------
;; GL utilities
;; void establish_gl_context(void);
(cffi:defcfun "establish_gl_context" :void)
;; void clear_buffers(void);
(cffi:defcfun "clear_buffers" :void)
