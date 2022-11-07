import scala.annotation.tailrec

def fib(n: Int): Int = {
  if (n == 0)
    0
  else if (n == 1)
    1
  else
    fib(n - 1) + fib(n - 2)
}

def fibTail(n: Int): Int = {
  @tailrec
  def calculateFibNumber(a: Int, b: Int, n: Int): Int = {
    if (n > 0)
      calculateFibNumber(b, a + b, n - 1)
    else
      a
  }
  calculateFibNumber(0, 1, n)
}

fib(0)
fib(1)
fib(9)
fib(44)

fibTail(0)
fibTail(1)
fibTail(9)
fibTail(44)
