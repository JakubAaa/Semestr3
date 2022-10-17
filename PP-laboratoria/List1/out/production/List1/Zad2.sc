def roots(a: Double, b: Double, c: Double): Int = {
  val delta = scala.math.pow(b, 2) - 4 * a * c
  if (delta > 0)
    2
  else if(delta == 0)
    1
  else
    0
}

roots(1.123, 5, 3.13) //delta = 2
roots(1, 2, 3)
roots(1, 4, 4)
