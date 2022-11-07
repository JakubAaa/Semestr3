let rec initSegment = fun (list1, list2) ->
  match list1 with
  | [] -> true
  | h :: t when list2 != [] && h = List.hd list2 -> initSegment(t, List.tl list2)
  | _ -> false;;

initSegment([1;2;3;4;5], [1;2;3;4;5;6;7;8]);;
initSegment([1;2;3;4;5], [1;2]);;
initSegment([3;2;1], [1;2]);;
initSegment([], []);;
initSegment([1;2;3;4], [1;2;3;4]);;