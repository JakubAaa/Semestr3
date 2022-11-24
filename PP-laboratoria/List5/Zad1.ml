type award = Item of string | Money of int | Ticket of (unit -> award) | Nothing;;
type ticket = HiddenTicket of (unit -> award) | UnHiddenTicket of award;;

let rec buyTicket list index =
  let checkAwardType a =
    match a with
    | Ticket(f) -> HiddenTicket(f)
    | _ -> UnHiddenTicket(a)
  in
  match list with
  | [] -> []
  | HiddenTicket(f) :: t when index = 1 -> checkAwardType (f()) :: t
  | h :: t -> h :: buyTicket t (index - 1);;

let ticket1 = HiddenTicket(fun() -> Item("Bike"));;
let ticket2 = HiddenTicket(fun() -> Money(1000));;
let ticket3 = HiddenTicket(fun() -> Ticket(fun() -> Ticket(fun() -> Item("Car"))));;
let ticket4 = HiddenTicket(fun() -> Nothing);;

let exampleList1 = [ticket1; ticket2; ticket3; ticket4];;

let tableAfter1Move = buyTicket exampleList1 2;;
let tableAfter2Moves = buyTicket tableAfter1Move 3;;
let tableAfter3Moves = buyTicket tableAfter2Moves 3;;
let tableAfter4Moves = buyTicket tableAfter3Moves 3;;
let tableAfter5Moves = buyTicket tableAfter4Moves 1;;
let tableAfter6Moves = buyTicket tableAfter5Moves 4;;
let tableAfter7Moves = buyTicket tableAfter6Moves 4;;

buyTicket exampleList1 12;;
buyTicket [] 12;;

let rec generateTable length =
  let rec matchAward number =
    match number with
    | 0 -> Money(Random.int 1000)
    | 1 -> Item("Bike")
    | 2 -> Ticket(fun() -> matchAward (Random.int 4))
    | _ -> Nothing
  in
  match length with
  | 0 -> []
  | _ -> HiddenTicket(fun() -> matchAward (Random.int 4)) :: generateTable (length - 1);;

let list1 = buyTicket (generateTable 2) 2;;
let list2 = buyTicket list1 2;;
let list3 = buyTicket list2 1;;

let list11 = buyTicket (generateTable 6) 2;;
let list12 = buyTicket list11 3;;
let list13 = buyTicket list12 3;;
let list14 = buyTicket list13 6;;
let list15 = buyTicket list14 5;;
let list16 = buyTicket list15 4;;
let list17 = buyTicket list16 1;;