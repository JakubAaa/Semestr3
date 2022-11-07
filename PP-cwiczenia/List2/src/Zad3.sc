val epsilon = 1.0e-15

def calculateRoot3(xi: Double, a: Double): Double = {
  if (math.abs(math.pow(xi, 3) - a) <= epsilon * math.abs(a))
    xi
  else
    calculateRoot3(xi + ((a / math.pow(xi, 2) - xi) / 3), a)
}

def root3M(a: Double): Double = {
  if (a > 1)
    calculateRoot3(a / 3, a)
  else
    calculateRoot3(a, a)
}

val root3F = (a: Double) => calculateRoot3(if (a > 1) a / 3 else a, a)

root3M(27)
root3M(26)
root3F(27)
root3F(26)