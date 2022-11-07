let split2Tail = fun list ->
  let rec split = fun (list, list1, list1Length, list2, list2Length) ->
    match list with
    (* |  _ :: t when t = [] && list1Length = list2Length -> (list1, list2) *)
    |  h :: t when list1Length > list2Length -> split(t, list1, list1Length, h :: list2, list2Length + 1)
    |  h :: t -> split(t, h :: list1, list1Length + 1, list2, list2Length)
    | _ -> (list1, list2)
  in
  split(list, [], 0, [], 0);;

  split2Tail [1; 2; 3; 4; 5; 6; 7; 8; 9];;
  split2Tail [1; 2; 3; 4; 5; 6; 7; 8];;
  split2Tail ["s1"; "s2"; "s3"; "s4"; "s5"];;
  split2Tail ["s1"; "s2"; "s3"; "s4"];;
  split2Tail [true, false];;
  split2Tail [true];;
  split2Tail [];;