let rec fib = fun n ->
  if n = 0
    then 0
else if n = 1
  then 1
else
  fib(n - 1) + fib(n - 2);;

let fibTail = fun n -> 
  let rec calculateFibNumber = fun(a, b, n) ->
    if n > 0
      then calculateFibNumber(b, a + b, n - 1)
    else
      a
  in
  calculateFibNumber(0, 1, n);;

fib 0;;
fib 1;;
fib 9;;
fib 40;;

fibTail 0;;
fibTail 1;;
fibTail 9;;
fibTail 40;;