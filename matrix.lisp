;; (aref array row col)

(defun mul-33-33 (a b)
  (let ((m (make-array '(3 3) :element-type 'single-float)))
    (dotimes (r 3)
      (dotimes (c 3)
        (setf (aref m r c)
              (+ (* (aref a r 0) (aref b 0 c))
                 (* (aref a r 1) (aref b 1 c))
                 (* (aref a r 2) (aref b 2 c))))))
    m))

(defun mul-44-44 (a b)
  (let ((m (make-array '(4 4) :element-type 'single-float)))
    (dotimes (r 4)
      (dotimes (c 4)
        (let ((sum 0.0))
          (dotimes (j 4)
            (incf sum (* (aref a r j) (aref b j c))))
          (setf (aref m r c) sum))))
    m))

(defun load-i-33 ()
  (make-array '(3 3) :element-type 'single-float
              :initial-contents '((1.0 0.0 0.0)
                                  (0.0 1.0 0.0)
                                  (0.0 0.0 1.0))))

(defun load-i-44 ()
  (make-array '(4 4) :element-type 'single-float
              :initial-contents '((1.0 0.0 0.0 0.0)
                                  (0.0 1.0 0.0 0.0)
                                  (0.0 0.0 1.0 0.0)
                                  (0.0 0.0 0.0 1.0))))

(defun mul-33-v3 (a v)
  (let ((vec (make-array '(3) :element-type 'single-float)))
    (dotimes (r 3)
      (setf (aref vec r)
            (let ((sum 0.0))
              (dotimes (j 3)
                (incf sum (* (aref a r j) (aref v j))))
              sum)))
    vec))

(defun mul-44-v4 (a v)
  (let ((vec (make-array '(4) :element-type 'single-float)))
    (dotimes (r 4)
      (setf (aref vec r)
            (let ((sum 0.0))
              (dotimes (j 4)
                (incf sum (* (aref a r j) (aref v j))))
              sum)))
    vec))

#|
(let ((m33 #2a((1.0 2.0 3.0)
               (4.0 5.0 6.0)
               (7.0 8.0 9.0)))
      (v3  #1a(1.0 2.0 3.0))
      (m44 #2a((1.0 2.0 3.0 4.0)
               (4.0 3.0 2.0 1.0)
               (1.0 2.0 3.0 4.0)
               (5.0 6.0 7.0 8.0)))
      (v4 #1a(1.0 2.0 3.0 4.0)))
  (mul-33-v3 m33 v3)
  (mul-44-44 m44 m44)
  (mul-44-v4 m44 v4))
|#

#|
M : matrix([1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]);
V : transpose(matrix([1,2,3]));
M4 : matrix(
    [1, 2, 3, 4],
    [4, 3, 2, 1],
    [1, 2, 3, 4],
    [5, 6, 7, 8]);
V4 : transpose(matrix([1.0, 2.0, 3.0, 4.0]));
|#
