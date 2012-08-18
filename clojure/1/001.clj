(defn modTF [lim]
  (time (reduce + (filter #(or (zero? (mod % 3))
                         (zero? (mod % 5)))
                     (range 1 (+ lim 1))))))
