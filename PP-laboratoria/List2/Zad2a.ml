let split2Rec = fun startList ->
  let addToList1 = fun (tail, toAdd, pair, list1Length, list2Length, splitFun) -> 
    let (list1, list2) = splitFun(tail, pair, list1Length + 1, list2Length)
    in
      (toAdd :: list1, list2)
  in
  let addToList2 = fun (tail, toAdd, pair, list1Length, list2Length, splitFun) ->
    let (list1, list2) = splitFun(tail, pair, list1Length, list2Length + 1)
    in
      (list1, toAdd :: list2)
  in
  let rec split = fun (list, pair, list1Length, list2Length) ->
    match list with
    (* |  _ :: t when t = [] && list1Length = list2Length -> pair *)
    |  h :: t when list1Length > list2Length -> addToList2(t, h, pair, list1Length, list2Length, split)
    |  h :: t -> addToList1(t, h, pair, list1Length, list2Length, split)
    |  _ -> pair
  in
  split(startList, ([], []), 0, 0);;

  split2Rec [1; 2; 3; 4; 5; 6; 7; 8; 9];;
  split2Rec [1; 2; 3; 4; 5; 6; 7; 8];;
  split2Rec ["s1"; "s2"; "s3"; "s4"; "s5"];;
  split2Rec ["s1"; "s2"; "s3"; "s4"];;
  split2Rec [true; false];;
  split2Rec [true];;
  split2Rec [];;