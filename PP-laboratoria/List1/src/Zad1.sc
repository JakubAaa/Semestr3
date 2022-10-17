def flip5[A, B, C, D, E](tuple: (A, B, C, D, E)): (D, E, C, B, A)  = {
  (tuple._4, tuple._5, tuple._3, tuple._2, tuple._1)
}

flip5(("a", 1, "b", 2, 3)) // expect: (2,3,b,1,a)
flip5((1, 2, 3, 4, 5)) // expect: (4,5,3,2,1)
flip5((true, false, 'a', 1, "string")) // expect: (1, string,a,false,true)