let find list toFind =
  let rec findIndex = fun (list, toFind, index) ->
    match list with
    |  h :: t when h = toFind -> index :: findIndex(t, toFind, index + 1)
    |  _ :: t -> findIndex(t, toFind, index + 1)
    |  _ -> []
in
findIndex(list, toFind, 0);;

let find123 = find [1; 2; 3];;

let find1212121212 = find [1; 2; 1; 2; 1; 2; 1; 2; 1; 2];;

find [1; 2; 6; 3; 4; 5; 6; 7; 8] 6;;
find [] 6;;
find [1; 2; 4; 5; 6; 7; 8] 3;;
find ["a"; "b"; "c"; "a"; "a"] "a";;
find [] "a";;
find ["b"; "c"; "d"; "e"; "f"] "a";;

find123 2;;
find123 5;;
find1212121212 1;;
find1212121212 3;;