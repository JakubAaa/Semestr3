def area(range: (Double, Double))(func: Double => Double)(n: Int): Double = {
  val dx = (range._2 - range._1) / n
  val pointsTableWithoutLastPoint = for (x <- List.range(1, n)) yield x
  val pointsTableWithLastPoint = n :: pointsTableWithoutLastPoint

  val st = (pointsTableWithLastPoint map (x => func((range._1 + x * dx) - dx / 2)) foldLeft 0.0)((sum, x) => sum + x)
  val s = (pointsTableWithoutLastPoint map (x => func(range._1 + x * dx)) foldLeft 0.0)((sum, x) => sum + x)

  (dx / 6) * (func(range._1) + func(range._2) + 2 * s + 4 * st)
  }

area(2, 12)(x => x*x + 2*x)(10)
area(2, 12)(x => x*x + 2*x)(1000000)

area(0, 12)(x => 2*x)(10)
area(0, 12)(x => 2*x)(1000000)

area(2, 12)(_ => 1)(10)
area(2, 12)(_ => 1)(1000000)

area(2, 12)(_ => 0)(10)
area(2, 12)(_ => 0)(1000000)


area(2, 12)(x => x*x + 2*x)(100)
area(2, 12)(x => x*x)(100) + area(2, 12)(x => 2*x)(100)

area(2, 12)(x => 5*x*x)(100)
5 * area(2, 12)(x => x*x)(100)

area(2, 12)(x => x*x)(100)
-area(12, 2)(x => x*x)(100)

area(2, 2)(_ => 1)(100)

area(2, 12)(x => x*x + 2*x)(100)
area(2, 5.5)(x => x*x + 2*x)(100) + area(5.5, 12)(x => x*x + 2*x)(100)

