(ql:quickload 'cffi)

(mapcar #'cffi:load-foreign-library
        '(#p"/usr/lib/libGLEW.so"
          #p"/usr/lib/libglfw.so"
          #p"./c/liblispcaftc.so"))

;; void* init_glfw(int width, int height, const char* title);
(cffi:defcfun "init_glfw" :pointer
  (width :int) (height :int) (title :pointer))

(cffi:with-foreign-string (title "hello gl")
  (init-glfw 640 480 title))
