type 'a bt = Empty | Node of 'a * 'a bt * 'a bt;;

let tt = Node(1,
              Node(2,
                    Node(4,
                          Empty,
                          Empty
                        ),
                    Empty
                  ),
              Node(3,
                    Node(5,
                          Empty,
                          Node(6,
                                Empty,
                                Empty
                              )
                          ),
                      Empty
                  )
              );; 

let breadthBT tree =
  let rec breadth queue =
    match queue with
    | [] -> []
    | h::t -> 
      match h with
      | Node(v, l, r) -> v::breadth (t@[l; r])
      | Empty -> breadth t in
      breadth [tree];;
breadthBT tt;;
