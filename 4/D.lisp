(defun split(string &optional (separator " ") (r nil))
  (let ((n (position separator string
         :from-end t
         :test #'(lambda (x y)
             (find y x :test #'string=)))))
    (if n
      (split (subseq string 0 n) separator (cons (subseq string (1+ n)) r))
      (cons string r))))

(defun range (l r)
  (if (= l r) nil
    (cons l (range (1+ l) r))))

(defun transpose (M)
  (apply #'map 'vector #'vector (coerce M 'list)))

(defun dot (a b)
  (apply #'+ (coerce (map 'vector #'* a b) 'list)))

(defun mulv (M v)
  (map 'vector (lambda (x) (dot x v)) M))

(defun mul (A B)
  (transpose 
    (map 'vector
      (lambda (v) (mulv A v)) 
      (transpose B))))

(defun I (n)
  (if (vectorp n)
    (I (length n))
    (let ((r (range 0 n)))
      (map 'vector
        (lambda (i) 
          (map 'vector
            (lambda (j) 
              (if (= i j) 1 0))
            r))
        r))))

(defun pow (M p)
  (if (zerop p) 
    (I M)
    (let ((h (pow M (floor p 2))))
      (mul (mul h h) (if (oddp p) M (I M))))))


;(defvar *input* (open "problem1.in"))
(defvar *input* *STANDARD-INPUT*)

(defvar n (read *input*))
(defvar m (read *input*))
(defvar k (read *input*))
(defvar l (read *input*))
(defvar term (mapcar (lambda (_) (read *input*)) (range 0 k)))


(defvar is_term (make-array (1+ n))) ;make-list
(mapc (lambda (i) (setf (aref is_term i) 1)) term)


(defvar table 
  (map 'vector
    (lambda (_)
      (make-array (1+ n)))
    (range 0 (1+ n))))

(loop for x from 1 to m do
  (apply 
    (lambda (v u sym-str)
      (let ((vi (parse-integer v)) (ui (parse-integer u)) (sym (char sym-str 0)))
        (incf (aref (aref table vi) ui))))
    (split (read-line *input*) " ")))

(write
  (dot
    (aref (pow table l) 1)
    is_term))
