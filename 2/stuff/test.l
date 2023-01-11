#!/usr/bin/env clisp

(defun sm (x)
    (if (not (= x 0))
    	(+ x (sm (read)))
    	0
    )
)


(defun fib (n) 
    (if (< n 2) 
        n
        (+ (fib (- n 1)) (fib (- n 2)))
    )
)

#|
(defun memo (fn name key test)
  "Return a memo-function of fn"
  (let ((table (make-hash-table :test test)))
    (setf (get name 'memo) table)
    #'(lambda (&rest args)
        (let ((k (funcall key args)))
          (multiple-value-bind (val found-p)
              (gethash k table)
            (if found-p
                val
                (setf (gethash k table) (apply fn args))))))))

(defun memoize (fn-name &key (key #'first) (test #'eql))
  "Replace fn-name's global definition with a memoized version"
  (setf (symbol-function fn-name)
    (memo (symbol-function fn-name) fn-name key test)))



(memoize fib) ;|#


(defun main ()
;	(trace sm)
;	(princ (sm (read)))
    (princ (fib 30))
    0
)


(exit (main ))

; (concatenate 'string "hello" "world")
; (concatenate 'list (1 2 3) (4 5 6)) ~
; (cons 'vsl (not 'dead))
; (eval (compile "(printc \"Hello world\")"))
; https://www.linux.org.ru/forum/development/1587106
; (loop (princ (eval (read))))

; (cons 1 (cons 2 (cons 3 nil)))
; (list 1 2 3)

;https://habr.com/ru/post/576278/
;https://stackoverflow.com/questions/256507/how-do-i-memoize-a-recursive-function-in-lisp

; dotimes

#|
; http://homelisp.ru/help/lisp.html
(defun printem (&rest args)
    (dolist (el args) 
        (princ el) 
        (princ #\SPACE)) (terpri))
(defun lfact (n) (setq r 1) (loop for i from 1 to n do (setq r (* r i))) r)
(defun fact (n) (if (= n 0) 1 (* n (fact (- n 1)))))

;(loop do (princ (lfact (read))) (terpri))

(defun solve1 (st e) (if (> st e) 0 (if (= st e) 1 (+ (solve (+ st 1) e) (solve (+ st 2) e) (solve (* st 3) e)))))
(princ (* (solve1 2 8) (solve1 8 10) (solve1 10 12))) (terpri)
(terpri)


(setq used (loop for i from 0 to 1000 collect 0))
(defun solve (s deep)
    (if (= deep 0) (progn
        (if (= (nth s used) 1)
            0
            (progn (setf (nth s used) 1) 1))) 
        (+ (solve (+ s 2) (- deep 1)) (solve (+ s 3) (- deep 1)) (solve (* s 2) (- deep 1)))))

(princ (solve 10 5)) (terpri)


(defun unisolver (operator p)
    1
)
|#