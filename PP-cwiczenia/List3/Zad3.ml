let rec sumProd list =
List.fold_left (fun (s, p) x -> (s + x, p * x)) (0,1) list;;

sumProd [1;2;3;4;5];;