(ns euler006.core)

(defn sq-sum
  [n]
  (#(* % %) (reduce + (range (inc n)))))

(defn sum-sq
  [n]
  (reduce + (map #(* % %) (range (inc n)))))
