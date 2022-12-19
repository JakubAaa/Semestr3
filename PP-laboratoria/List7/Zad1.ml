module type COMPARATOR =
sig
  type 'a toCompare
  type result = int
  val compareTo: 'a -> 'a -> result
end;; 

module Comparator: COMPARATOR =
struct
  type 'a toCompare = int 
  type result = int
  let compareTo a b = 
    if a > b
      then 1
    else if a = b
      then 0
    else -1
end;;

module ReverseComparator : COMPARATOR =
struct
  type 'a toCompare = int
  type result = int
  let compareTo a b =  
    if a > b
      then -1
    else if a = b
      then 0
    else 1
end;;

module PriorityQueueImpl =
  struct
    type 'a heap = {array: 'a array; compareTo: 'a -> 'a -> int}
    exception EmptyQueue of string

    let create compareTo = ref {array = [||]; compareTo = compareTo}

    let size heap = 
      Array.length !heap.array

    let swap firstIndex secondIndex heap =
      let temp = !heap.array.(firstIndex) in 
        !heap.array.(firstIndex) <- !heap.array.(secondIndex);
        !heap.array.(secondIndex) <- temp;;

    let insert elem heap =
      heap := {array = Array.append !heap.array [|elem|]; compareTo = !heap.compareTo};  
      let elementIndex = ref (size heap - 1) in
        while !elementIndex > 0 && !heap.compareTo !heap.array.(!elementIndex) !heap.array.(!elementIndex / 2) > 0 do
            swap (!elementIndex) (!elementIndex / 2) heap;
            elementIndex := !elementIndex / 2
        done;;

    let rec fixHeap heap index = 
      let largest = ref index in
      let left = (index + 1) * 2 - 1 in 
      let right = left + 1 in 
        if left < size heap && !heap.compareTo !heap.array.(left) !heap.array.(!largest) > 0 
          then largest := left;
        if right < size heap && !heap.compareTo !heap.array.(right) !heap.array.(!largest) > 0  
          then largest := right;
        if !largest != index then
          begin
            swap !largest index heap;
            fixHeap heap !largest
          end;;

    let retrive heap = 
      if size heap = 0 
        then raise (EmptyQueue "Queue is empty!!!")
      else
        let first = !heap.array.(0) in
            !heap.array.(0) <- !heap.array.((size heap) - 1);
            heap := {array = Array.sub !heap.array 0 ((size heap) - 1); compareTo = !heap.compareTo};
            fixHeap heap 0;
            first 
end;;

module type PRIORITYQUEUE =
sig
  type 'a heap
  exception EmptyQueue of string
  val create: ('a -> 'a -> int) -> 'a heap ref
  val insert: 'a -> 'a heap ref -> unit
  val retrive: 'a heap ref -> 'a
end;;

module PriorityQueue: PRIORITYQUEUE = PriorityQueueImpl;;

let queue1 = PriorityQueueImpl.create(Comparator.compareTo);;
PriorityQueueImpl.insert 1 queue1;;
PriorityQueueImpl.insert 2 queue1;;
PriorityQueueImpl.insert 10 queue1;;
PriorityQueueImpl.insert 9 queue1;;
PriorityQueueImpl.insert 7 queue1;; 
PriorityQueueImpl.insert 4 queue1;; 
PriorityQueueImpl.insert 15 queue1;; 
PriorityQueueImpl.insert 1 queue1;; 
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;
PriorityQueueImpl.retrive queue1;;

let queue2 = PriorityQueue.create(ReverseComparator.compareTo);;
PriorityQueue.insert 1 queue2;;
PriorityQueue.insert 15 queue2;;
PriorityQueue.insert 3 queue2;;
PriorityQueue.insert 7 queue2;;
PriorityQueue.insert 4 queue2;;
PriorityQueue.insert 8 queue2;;
PriorityQueue.insert 8 queue2;;
PriorityQueue.insert 20 queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;
PriorityQueue.retrive queue2;;

let queue3 = PriorityQueue.create(Comparator.compareTo);;
PriorityQueue.insert 1 queue3;;
PriorityQueue.retrive queue3;;
PriorityQueue.retrive queue3;;