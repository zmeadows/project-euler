(defpackage :euler001
  (:use :common-lisp))

(in-package :euler001)

(defun mult-below (n)
  (let ((sum 0))
    (dotimes (x n)
      (if (or (= (mod x 3) 0) (= (mod x 5) 0))
        (setf sum (+ sum x))))
    sum))
