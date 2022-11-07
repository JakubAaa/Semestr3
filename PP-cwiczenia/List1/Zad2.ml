let rec count = fun(a, list) ->
  if list = []
    then 0
  else if List.hd list = a
    then 1 + count(a, List.tl list)
  else
    count(a, List.tl list);;

count('a', ['a'; 'b'; 'c'; 'a'; 'd'; 'a'; 'a']);;
count(true, [false; true; false; true; true; false]);;
count(false, []);;
count(1, [0; 2; 3; 4]);;