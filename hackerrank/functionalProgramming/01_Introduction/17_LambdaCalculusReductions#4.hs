{-
       (λg.( (λf.( (λx.(f (x x))) (λx.(f (x x))) ) ) g))
    => (λg. (λx.(g (x x)))(λx.(g (x x))) )
    => (λg. g ((λx.(g (x x))) (λx.(g (x x)))) )
    => CAN'T REDUCE
-}