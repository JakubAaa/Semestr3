def replicate[T](a: T, i: Int): List[T] = {
  if (i <= 0)
    Nil
  else
    a :: replicate(a, i - 1)
}

replicate(2, 5)
replicate('a', 8)
replicate(true, 0)
replicate("string", -4)
replicate("string", 4)