let rec listLength = fun(list) ->
  if list = []
    then 0
  else
    1 + listLength(List.tl list);;

listLength([]);;
listLength(["String"]);;
listLength([1; 2]);;
listLength(['a'; 'b'; 'c']);;
listLength([true; false; true; false]);;
listLength([1.11; 2.22; 3.33; 4.44; 5.55]);;