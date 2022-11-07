let rec flatten1 = fun(list) ->
  if list = []
    then []
  else
    List.hd list@flatten1(List.tl list);;
    
flatten1([]);;
flatten1([[]; []; []; []]);;
flatten1([[1; 2]; [3; 4]; [5; 6]]);;
flatten1([['a'; 'b'; 'c']; ['e'; 'f'; 'g']]);;
flatten1([[true]; [false]; [true]; [false]]);;
