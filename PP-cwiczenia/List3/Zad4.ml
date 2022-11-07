let rec quicksort = function
 [] -> []
 | [x] -> [x]
 | xs -> let small = List.filter (fun y -> y < List.hd xs ) xs
 and large = List.filter (fun y -> y >= List.hd xs ) xs
 in quicksort small @ quicksort large;;

 let rec quicksort' = function
 [] -> []
 | x::xs -> let small = List.filter (fun y -> y < x ) xs
 and large = List.filter (fun y -> y > x ) xs
 in quicksort' small @ (x :: quicksort' large);;

 quicksort' [4;2;5;3;9;1;0;3;56;89;65;-89;23;65;34;-5];;
 quicksort [4;2;-8];;
 quicksort [4;2;4];;

