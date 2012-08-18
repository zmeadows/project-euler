(ns euler005.core)

(defn div-by
  [n d]
  (not-any? #(not= % 0)
       (map #(mod n %) (range 2 (inc d)))))
