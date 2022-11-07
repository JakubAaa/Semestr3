let curry func a b c = func(a, b, c);;

let unCurry func(a, b, c) = func a b c;;
