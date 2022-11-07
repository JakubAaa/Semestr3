let rec sqrList = fun(list) ->
  if list = []
    then []
  else
    List.hd list * List.hd list :: sqrList(List.tl list);;

sqrList([]);;
sqrList([0]);;
sqrList([2; 14]);;
sqrList([-8; 1; 2; 3; 4; 5; 6; 7; 8; 9]);;