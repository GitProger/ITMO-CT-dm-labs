;https://lispcookbook.github.io/cl-cookbook/iteration.html
;https://stackoverflow.com/questions/3813895/how-can-i-read-the-contents-of-a-file-into-a-list-in-lisp

;(setf *STANDARD-INPUT* (open "problem1.in" :direction :input))
;(setf *STANDARD-OUTPUT* (open "problem1.out" :direction :output :if-exists :overwrite))
;(defvar *input* (open "problem1.in" :direction :input))

(defvar *input* (open "problem1.in"))

(defun split(string &optional (separator " ") (r nil))
  (let ((n (position separator string
         :from-end t
         :test #'(lambda (x y)
             (find y x :test #'string=)))))
    (if n
      (split (subseq string 0 n) separator (cons (subseq string (1+ n)) r))
      (cons string r))))

(defun readlist ()
  (mapcar #'parse-integer (split (read-line *input*) " ")))


(defvar w (read-line *input*))
(defvar n (read *input*))
(defvar m (read *input*))
(defvar k (read *input*))
; (apply #'(lambda (n_ m_ k_)
;            (defvar n n_) (defvar m m_) (defvar k k_))
;   (readlist))
(defvar acceptable (readlist))

(defvar *g* (make-hash-table))


(loop for x from 1 to m do
  (apply 
    (lambda (v u sym-str)
      (let ((vi (parse-integer v)) (ui (parse-integer u)) (sym (char sym-str 0)))
;        (mapcar #'princ (list vi " " ui " " sym #\newline))
        (if (null (gethash vi *g*))
          (setf (gethash vi *g*) (make-hash-table)))
        (setf (gethash sym (gethash vi *g*)) ui)))
    (split (read-line *input*) " ")))


; (defun go (dfa sym state) ; if name is `go` -> error
;   (gethash sym (gethash state dfa)))
; (defun pass (dfa str state)
;   (if (zerop (length str))
;     state
;     (pass dfa
;           (subseq str 1)  ; O(n)
;           (go dfa (char str 0) state))))

(defun next (dfa sym state)
  (gethash sym (gethash state dfa)))
(defun pass (dfa state str)
  (if (null str)
    state
    (pass dfa 
          (next dfa (car str) state)
          (cdr str))))


(defun put (x)
  (with-open-file (str "problem1.out"
                     :direction :output
                     :if-exists :supersede
                     :if-does-not-exist :create)
    (format str x)))

(put
  (if (find (pass *g* 1 (coerce w 'list)) acceptable)
    "Accepts" "Rejects"))


;(close *STANDARD-OUTPUT*)
