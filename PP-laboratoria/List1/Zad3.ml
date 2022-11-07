let rec substitute = fun (list, a, b) -> 
  if list = [] 
    then [] 
  else if List.hd list = a 
    then b :: substitute(List.tl list, a, b)
  else 
    List.hd list :: substitute(List.tl list, a, b);;

substitute([], 1, 2);;                                          (* expect: [] *)
substitute([1; 2; 3; 4; 2], 2, 9);;                             (* expect: [1; 9; 3; 4; 9] *)
substitute(["a"; "b"; "c"; "d"; "a"], "a", "e");;               (* expect: ["e"; "b"; "c"; "d"; "e"] *)
substitute(['a'; 'c'; 'c'; 'c'; 'a'], 'c', 'f');;               (* expect: ['a'; 'f'; 'f'; 'f'; 'a'] *)
substitute([true; false; false; true; true], true, false);;     (* expect: [false; false; false; false; false] *)