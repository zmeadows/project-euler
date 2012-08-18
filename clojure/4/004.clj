(defn revNum [n]
  (loop [cut n rev 0]
    (if (zero? cut)
      rev
      (recur (quot cut 10)
             (+ (* rev 10) (mod cut 10))))))

(defn isPalin [n]
  (= n (revNum n)))

(def euler4
  (reduce max
    (filter isPalin (for
                      [a (range 100 1000)
                       b (range 100 1000)
                       :when (> b a)]
                      (* a b)))))
