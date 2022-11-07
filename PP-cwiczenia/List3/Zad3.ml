let rec sumProd xs =
  match xs with
  | h::t -> let(s,p) = sumProd t
in
  (h +s, h*p)
| [] -> (0,1);;