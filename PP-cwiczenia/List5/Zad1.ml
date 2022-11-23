type 'a llist = LNil | LCons of 'a * 'a llist Lazy.t;;

let rec toLazyList = function
 [] -> LNil
 | x :: xs -> LCons(x, lazy (toLazyList xs));;

 let rec ltake = function
 (0, _) -> []
 | (_, LNil) -> []
 | (n, LCons(x, lazy xs)) -> x :: ltake(n-1, xs);;

  let lrepeat k llist =
    let rec repeat counter list =
      match (counter, list) with
      | (_, LNil) -> LNil
      | (0, LCons(_, lazy t)) -> repeat k t
      | (counter, LCons(h, lazy t)) -> LCons(h, lazy (repeat (counter - 1) list)) 
    in
    repeat k llist;;

ltake(100, lrepeat 3 (toLazyList [1;2;3;4]))