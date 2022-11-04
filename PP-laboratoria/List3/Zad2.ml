let area  (xp, xk) func n =
  let dx = (xk -. xp) /. n
  in
  let rec createTable = fun i ->
    if i < n
      then i :: createTable(i +. 1.)
    else
      []
    in
  let pointsTableWithoutLastPoint = createTable 1.
  in
  let pointsTableWithLastPoint = n :: pointsTableWithoutLastPoint
  in
  let st = List.fold_left(+.) 0. (List.map (fun x -> func((xp +. x *. dx) -. dx /. 2.)) pointsTableWithLastPoint)
  in
  let s = List.fold_left(+.) 0. (List.map (fun x -> func(xp +. x *. dx)) pointsTableWithoutLastPoint)
  in
(dx /. 6.) *. (func xp +. func xk +. 2. *. s +. 4. *. st);;

area (2., 12.) (fun x -> x*.x +. 2.*.x) 10.;;
area (2., 12.) (fun x -> x*.x +. 2.*.x) 10000.;;

area (0., 12.) (fun x -> 2.*.x) 10.;;
area (0., 12.) (fun x -> 2.*.x) 10000.;;

area (2., 12.) (fun _ -> 1.) 10.;;
area (2., 12.) (fun _ -> 1.) 10000.;;

area (2., 12.) (fun _ -> 0.) 10.;;
area (2., 12.) (fun _ -> 0.) 10000.;;


area (2., 12.) (fun x -> x*.x +. 2.*.x) 100.;;
area (2., 12.) (fun x -> x*.x) 10. +. area (2., 12.) (fun x -> 2.*.x) 10.;;

area (2., 12.) (fun x -> 5. *. x*.x) 100.;;
5. *. area (2., 12.) (fun x ->x*.x) 100.;;

area (2., 12.) (fun x -> x*.x) 100.;;
-. area (12., 2.) (fun x -> x*.x) 100.;;

area (2., 2.) (fun x -> x*.x) 100.;;

area (2., 12.) (fun x -> x*.x +. 2.*.x) 100.;;
area (2., 5.5) (fun x -> x*.x +. 2.*.x) 100. +. area (5.5, 12.) (fun x -> x*.x +. 2.*.x) 100.;;