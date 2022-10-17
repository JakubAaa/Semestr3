let rec swap2 = fun (list) -> 
  if list = [] 
    then [] 
  else if List.tl list = [] 
    then List.hd list :: []
  else 
    List.hd (List.tl list) :: List.hd list :: swap2( List.tl (List.tl list));;

swap2([]);;                                         (* expect: [] *)
swap2([1; 2; 3; 4; 5]);;                            (* expect: [2; 1; 4; 3; 5] *)
swap2([1.11; 2.22; 3.33; 4.44; 5.55; 6.66]);;       (* expect: [2.22; 1.11; 4.44; 3.33; 6.66; 5.55] *)
swap2(["a"; "b"; "c"; "d"; "e"; "f"]);;             (* expect: ["b"; "a"; "d"; "c"; "f"; "e"] *)
swap2([true; false; true; false; false]);;          (* expect: [false; true; false; true; false] *)