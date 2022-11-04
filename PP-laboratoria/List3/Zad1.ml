let rec (>=<) list func = 
  match list with
  | h :: [] -> []
  | h :: t -> func(h, List.hd t) :: ((List.tl) t >=< func)
  | _ -> []

let rec collaps = fun(list, func) ->
  match list with
  | h :: [] -> list
  | h :: t -> collaps(list >=< func, func)
  | _ -> [];;

let tableEven = [1;2;3;4;5;6;7;8];;
let tableOdd = [1;2;3;4;5;6;7;8;9];;

let addFunction = fun (a, b) -> a + b;;

tableEven >=< addFunction;;
tableOdd >=< addFunction;;
[] >=< addFunction;;

tableEven >=< addFunction >=< addFunction;;
tableOdd >=< addFunction >=< addFunction;;
[] >=< addFunction >=< addFunction;;

tableEven >=< addFunction >=< addFunction >=< addFunction;;


collaps(tableEven, addFunction);;
collaps(tableOdd, addFunction);;
collaps([], addFunction);;