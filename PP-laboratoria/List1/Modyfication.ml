let separate = fun list ->
  let rec split = fun (listInOrder, theBiggestElement, listWithRestElements, list) ->
    if list = []
      then (listInOrder, listWithRestElements)
    else if List.hd list > theBiggestElement 
      then split(List.hd list :: listInOrder, List.hd list, listWithRestElements, List.tl list)
    else
      split(listInOrder, theBiggestElement, List.hd list :: listWithRestElements, List.tl list)
    in
  split([], 0, [], list);;
  
separate([1;2;1;3;4;5;4;6;4;7;8;9;2]);;     (*expect: ([9; 8; 7; 6; 5; 4; 3; 2; 1], [2; 4; 4; 1]) *)
separate([1;2;3;4;5;6;7;8;9]);;             (*expect: ([9; 8; 7; 6; 5; 4; 3; 2; 1], []) *)
separate([1;2;3;7;8;9]);;                   (*expect: ([9; 8; 7; 2; 1], []) *)
separate([9;8;7;6;5;4;3;2;1]);;             (*expect: ([9], [1; 2; 3; 4; 5; 6; 7; 8]) *)
separate([]);;                              (*expect: ([], [])*)
separate [-1; 2; 1];;

(* let separate = fun(startedList) ->
  let rec split = fun(list, pair, theBiggestElement) ->
    if list = []
      then pair
    else if List.hd list > theBiggestElement 
      then split(List.tl list, (List.hd list :: fst pair, snd pair), List.hd list)
    else
      split(List.tl list, (fst pair, List.hd list :: snd pair), theBiggestElement)
    in
  split(startedList, ([], []), 0);;
  
separate([1;2;1;3;4;5;4;6;4;7;8;9;2]);;
separate([1;2;3;4;5;6;7;8;9]);;
separate([9;8;7;6;5;4;3;2;1]);;
separate([]);; *)
