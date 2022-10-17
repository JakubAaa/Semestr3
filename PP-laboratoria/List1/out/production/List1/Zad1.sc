def flip5[A, B, C, D, E](tuple: (A, B, C, D, E)): (D, E, C, B, A)  = {
  (tuple._4, tuple._5, tuple._3, tuple._2, tuple._1)
}

flip5(("a", 1, "b", 2, 3))