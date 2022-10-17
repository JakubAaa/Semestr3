def roots(a: Double, b: Double, c: Double): Int = {
  val delta = scala.math.pow(b, 2) - 4 * a * c
  if (delta > 0)
    2
  else if(delta == 0)
    1
  else
    0
}

roots(1, 5, 3) //delta = 16 expect: 2
roots(1.123, 5.5, 3.13) //delta = 16,19004 expect: 2
roots(1, 4, 4) //delta = 0 expect: 1
roots(1, 3, 4) //delta = -7 expect: 0
roots(1.2, 3.123, 4.1) //delta = -9,926871 expect: 0
