(use 'clojure.contrib.math)

(defn LPF [n]
  (loop [pf n i 2]
    (if (> i (int (sqrt pf)))
      pf
      (if (zero? (mod pf i))
        (recur (/ pf i) (inc i))
        (recur pf (inc i))))))
