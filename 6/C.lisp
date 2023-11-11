(defun put (x)
  (princ x)
  (princ #\space))
(defun putn (&rest x)
  (loop for a in x do (put a))
  (terpri))

(defun merge-sort (a cmp)
  (if (< (length a) 2) a
    (let ((n (truncate (length a) 2)))
      (merge 'list
        (merge-sort (subseq a 0 n) cmp)
        (merge-sort (subseq a n) cmp)
        cmp))))

(let ((ans
         (merge-sort
           (loop for i from 1 to (read) collect i)
           (lambda (i j)
             (putn 1 i j)
             (eq (read) 'YES)))))
  (put 0)
  (apply #'putn ans))

