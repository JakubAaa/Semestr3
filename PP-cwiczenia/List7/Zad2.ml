module type QUEUE_MUT =
sig
 type 'a t
 (* The type of queues containing elements of type ['a]. *)
 exception Empty of string
 (* Raised when [first q] is applied to an empty queue [q]. *)
 exception Full of string
 (* Raised when [enqueue(x,q)] is applied to a full queue [q]. *)
 val empty: int -> 'a t
 (* [empty n] returns a new queue of length [n], initially empty. *)
 val enqueue: 'a * 'a t -> unit
 (* [enqueue (x,q)] adds the element [x] at the end of a queue [q]. *)
 val dequeue: 'a t -> unit
 (* [dequeue q] removes the first element in queue [q] *)
 val first: 'a t -> 'a
 (* [first q] returns the first element in queue [q] without removing
 it from the queue, or raises [Empty] if the queue is empty. *)
 val isEmpty: 'a t -> bool
 (* [isEmpty q] returns [true] if queue [q] is empty,
 otherwise returns [false]. *)
 val isFull: 'a t -> bool
 (* [isFull q] returns [true] if queue [q] is full,
 otherwise returns [false]. *)
end;;

module QUEUE: QUEUE_MUT = struct
  type 'a t = {mutable f: int; mutable r: int; mutable l: int; mutable arr: 'a option array};;
  exception Empty of string;;
  exception Full of string;;
  let empty l = {f=0; r=0; l; arr=(Array.make l None)};;
  let isEmpty q = if q.arr.(q.f) = None then true else false;;
  let isFull q = if(q.f = q.r && q.arr.(q.f) != None) then true else false;;

  let enqueue (v, q) = if (isFull q) then raise (Full "Queue is full") else
    q.arr.(q.r) <- (Some v); q.r <- (q.r + 1) mod q.l;;
  let dequeue q = q.arr.(q.f) <- None; q.f <- (q.f + 1) mod q.l;;
  let first q = 
    match q.arr.(q.f) with
    | Some v -> v
    | None -> raise (Empty "Queue is empty");;
  end;;

let q = QUEUE.empty 4;;
QUEUE.enqueue (1, q);;
QUEUE.enqueue (2, q);;
QUEUE.enqueue (3, q);;
QUEUE.enqueue (4, q);;
QUEUE.isFull q;;
(* QUEUE.enqueue (5, q);; *)
QUEUE.first q;;
QUEUE.dequeue q;;
QUEUE.first q;;
QUEUE.dequeue q;;
QUEUE.dequeue q;;
QUEUE.dequeue q;;
QUEUE.isEmpty q;;
QUEUE.first q;;