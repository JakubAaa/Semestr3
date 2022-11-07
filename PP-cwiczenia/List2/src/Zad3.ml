let epsilon = 1.0e-15

let rec calculateRoot3 = fun (xi, a) 
  if abs_float ((xi *. xi *. xi) -. a) <= epsilon *. abs_float a
    then xi
  else
    calculateRoot3(xi +. (((a /. (xi  *. xi)) -. xi) /. 3.), a)

let root3M a =
  if a > 1.
    then calculateRoot3(a /. 3., a)
  else
    calculateRoot3(a, a);;

let root3F = fun a ->
  if a > 1.
    then calculateRoot3(a /. 3., a)
  else
    calculateRoot3(a, a);;

root3M(27.);;
root3M(26.);;

root3F(27.);;
root3F(26.);;