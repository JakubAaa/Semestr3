def lfib: LazyList[Int] = {
  def fib (a: Int, b: Int): LazyList[Int] =
    a #:: fib(b, a + b)

  fib(0, 1)
}

lfib.take(10).force