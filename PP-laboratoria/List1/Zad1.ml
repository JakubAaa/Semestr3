let flip5 = fun (a, b, c, d, e) -> (d, e, c, b, a);;

flip5(("a", 1, "b", 2, 3));;                  (* expect: (2, 3, "b", 1, "a") *)
flip5((1, 2, 3, 4, 5));;                      (* expect: (4, 5, 3, 2, 1) *)
flip5((true, false, 'a', 1, "string"));;      (* expect: (1, "string", 'a', false, true) *)
