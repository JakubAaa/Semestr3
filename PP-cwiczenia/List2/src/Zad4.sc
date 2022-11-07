def pattern[T](list: List[T]): Any = {
  list match
    case _ :: _ :: x :: _ :: _ if x == 0 => List(-2, -1, 0, 1, 2)
//    case _ :: (x2, _) => List((1, 2), (0, 1))
    case _ => "AAA"
}

pattern(List((1, 2), (3, 4)))
pattern(List(1, 2, 0, 4, 5))
pattern(List(1, 2, 3, 4))
pattern(List(1, 2, (1,2)))