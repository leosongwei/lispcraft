(ql:quickload 'cffi)

(load "~/.emacs.d/slime/start-swank.lisp")

(load "ffi.lisp")

;; ------------------------------------------------------------
;; module

(defstruct module
  vertex
  tex-coord
  normals
  texture)

(defun gen-module (vertex tex-coord normals)
  (make-module :vertex vertex
               :tex-coord tex-coord
               :normals normals))

(defparameter *quad*
  (gen-module #2a((0.0 0.0 -5.0)
                  (5.0 0.0 -5.0)
                  (5.0 5.0 -5.0)
                  (0.0 5.0 -5.0))
              #2a((0.0 0.0)
                  (1.0 0.0)
                  (1.0 1.0)
                  (0.1 0.1))
              #2a((0.0 0.0 1.0)
                  (0.0 0.0 1.0)
                  (0.0 0.0 1.0)
                  (0.0 0.0 1.0))))

;; ------------------------------------------------------------

#|
(defparameter *glfw-window-pointer*
  (cffi:with-foreign-string (title "hello world")
    (init-glfw 640 480 title)))

(establish-gl-context)
(clear-buffers)
(glfwSwapBuffers *glfw-window-pointer*)
|#

;;(glfwWindowShouldClose *glfw-window-pointer*)
;;(glfwTerminate)

