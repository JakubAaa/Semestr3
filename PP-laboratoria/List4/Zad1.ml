type operation = 
  CreateString of string | 
  InsertSubstring of int * string |
  DeleteSubstring of int |
  MoveSubstring of int * int;;

type snapshotsTree =
  Empty |
  Node of operation * snapshotsTree;;

let createNewString = fun value ->
   String.split_on_char ' ' value;;

let insertSubstring = fun (list, index, value) ->
  if index < 0 
    then []
  else
    let rec insert = fun(list, currentIndex) ->
      match list with
      | h :: t when currentIndex = index -> value :: h :: insert(t, currentIndex + 1)
      | h :: t -> h :: insert(t, currentIndex + 1)
      | _ when currentIndex <= index -> value :: []
      | _ -> [] 
    in
    insert(list, 0);;

let deleteSubstring = fun (list, index) ->
  if index < 0 || index >= List.length list
    then []
  else
    let rec delete = fun (list, currentIndex) ->
      match list with
      | _ :: t when currentIndex == index -> delete(t, currentIndex + 1)
      | h :: t -> h :: delete(t, currentIndex + 1)
      | _ -> []
    in
    delete(list, 0);;

let moveSubstring = fun (list, sourceIndex, destinationIndex) ->
  if sourceIndex < 0 || sourceIndex >= List.length list || destinationIndex < 0
    then []
  else if sourceIndex = destinationIndex
    then list
  else
    let rec getPartOfList = fun (list, indexFrom, indexTo, currentIndex) ->
      match list with
      | _ :: t when currentIndex < indexFrom -> getPartOfList(t, indexFrom, indexTo, currentIndex + 1)
      | h :: t when currentIndex >= indexFrom && currentIndex < indexTo -> h :: getPartOfList(t, indexFrom, indexTo, currentIndex + 1)
      | _ -> []
    in
  if sourceIndex < destinationIndex
      then getPartOfList(list, 0, sourceIndex, 0) @ 
              getPartOfList(list, sourceIndex + 1, destinationIndex + 1, 0) @ 
                List.nth list sourceIndex :: getPartOfList(list, destinationIndex + 1, List.length list, 0)
  else
    getPartOfList(list, 0, destinationIndex, 0) @
      List.nth list sourceIndex :: getPartOfList(list, destinationIndex, sourceIndex, 0) @
        getPartOfList(list, sourceIndex + 1, List.length list, 0);;

let applyOperation = fun (operation, oldVersion) ->
  match operation with
  | CreateString(value) -> createNewString value
  | InsertSubstring(index, value) -> insertSubstring(oldVersion, index, value)
  | DeleteSubstring(index) -> deleteSubstring(oldVersion, index)
  | MoveSubstring(sIndex, dIndex) -> moveSubstring(oldVersion, sIndex, dIndex);;

let review = fun(root, newOperation) ->
  let rec reviewRec = fun(tree, newString) ->
    match tree with
    | Empty -> newString
    | Node(op, tr) -> reviewRec(tr, applyOperation(op, newString))
  in
  let finalList = applyOperation(newOperation, reviewRec(root, []))
  in
  if finalList = []
    then "ERROR!"
  else
  String.concat " " finalList;;

(* TESTS - createNewString  *)
print_string "TESTS - createNewString";;
createNewString("Ala");;
let manyElementsList = createNewString("Ala ma kota");;

(* TESTS - insertSubstring *)
print_string "TESTS - insertSubstring";;
insertSubstring([], 0, "Ola");;
insertSubstring([], -5, "Ola");;
insertSubstring([], 5, "Ola");;

insertSubstring(manyElementsList, -5, "Ola");;
insertSubstring(manyElementsList, 0, "Ola");;
insertSubstring(manyElementsList, 1, "Ola");;
insertSubstring(manyElementsList, 3, "Ola");;
insertSubstring(manyElementsList, 7, "Ola");;

(* TESTS - deleteSubstring *)
print_string "TESTS - deleteSubstring";;
deleteSubstring([], -5);;
deleteSubstring([], 0);;
deleteSubstring([], 5);;

deleteSubstring(manyElementsList, -5);;
deleteSubstring(manyElementsList, 0);;
deleteSubstring(manyElementsList, 1);;
deleteSubstring(manyElementsList, 2);;
deleteSubstring(manyElementsList, 3);;

(* TESTS - moveSubstring *)
print_string "TESTS - moveSubstring";;
moveSubstring([], 0, 1);;
moveSubstring([], -5, 1);;

moveSubstring(manyElementsList, -5, 1);;
moveSubstring(manyElementsList, 1, -1);;
moveSubstring(manyElementsList, -1, -1);;
moveSubstring(manyElementsList, 0, 0);;
moveSubstring(manyElementsList, 0, 1);;
moveSubstring(manyElementsList, 0, 5);;
moveSubstring(manyElementsList, 2, 0);;
moveSubstring(manyElementsList, 2, 1);;

let exampleTree1 = Node(CreateString("Ala Ala kota ma"),
                        Node(InsertSubstring(3, "psa"),
                            Node(InsertSubstring(3, "i"),
                                Node(MoveSubstring(5, 2), Empty
                                    )
                                )
                            )
                        );;
review(exampleTree1, DeleteSubstring(0));;

let exampleTree2 = Node(CreateString("Ala ma kota"),
                        Node(InsertSubstring(-1, "psa"), Empty
                            )
                        );;
review(exampleTree2, DeleteSubstring(0));;

let exampleTree3 = Node(CreateString("Ala ma kota"),
                        Node(InsertSubstring(1, "psa"), Empty
                            )
                        );;
review(exampleTree3, DeleteSubstring(-5));;