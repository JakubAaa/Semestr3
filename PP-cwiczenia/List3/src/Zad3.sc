def sumProd(list: List[Int]): (Int, Int) =
  (list foldLeft (0,1))((sum, x) => (x + sum._1, x * sum._2))

sumProd(List(1,2,3,4,5))