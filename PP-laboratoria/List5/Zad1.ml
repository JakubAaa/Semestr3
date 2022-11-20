type award = Item of string | Money of float | Ticket of (unit -> award) | Nothing;;
type ticket = HiddenTicket of (unit -> award) | UnHiddenTicket of award;;
type board = ticket list;;

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


let itemAward = Item("Bike");;
let moneyAward = Money(999.99);;
let ticketAward = Ticket(fun() -> Ticket(fun() -> Item("Car")));;
let unluckyAward = Nothing;;

let ticket1 = HiddenTicket(fun() -> itemAward);;
let ticket2 = HiddenTicket(fun() -> moneyAward);;
let ticket3 = HiddenTicket(fun() -> ticketAward);;
let ticket4 = HiddenTicket(fun() -> unluckyAward);;

let exampleList1: board = [ticket1; ticket2; ticket3; ticket4];;

let tableAfter1Move = buyTicket exampleList1 2;;
let tableAfter2Moves = buyTicket tableAfter1Move 3;;
let tableAfter3Moves = buyTicket tableAfter2Moves 3;;
let tableAfter4Moves = buyTicket tableAfter3Moves 3;;
let tableAfter5Moves = buyTicket tableAfter4Moves 1;;
let tableAfter6Moves = buyTicket tableAfter5Moves 4;;
let tableAfter7Moves = buyTicket tableAfter6Moves 4;;

buyTicket exampleList1 12;;
buyTicket [] 12;;