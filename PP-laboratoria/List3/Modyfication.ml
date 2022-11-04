let reverse = fun list ->
  List.fold_left (fun acc x -> x  :: acc) [] list;;

reverse ['a';'b';'c';'d';'e';'f';'g'];;
reverse [1;2;3;4;5;6;7];;
reverse [1;2;3;4;5;6];;
reverse [];;