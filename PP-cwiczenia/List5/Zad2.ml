type 'a llist = LNil | LCons of 'a * 'a llist Lazy.t;;

let rec ltake = function
(0, _) -> []
| (_, LNil) -> []
| (n, LCons(x, lazy xs)) -> x :: ltake(n-1, xs);;

let lfib =
  let rec fib a b =
    LCons(a, lazy (fib b (a + b))) 
  in
  fib 0 1;;
ltake(12, lfib);;