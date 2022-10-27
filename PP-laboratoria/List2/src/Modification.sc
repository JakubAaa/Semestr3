def substitute[T](list: List[T])(a: T)(b: T): List[T] = {
  list match
    case h :: t if h == a => b :: substitute(t)(a)(b)
    case h :: t => h :: substitute(t)(a)(b)
    case _ => Nil
}

substitute(List(1, 2, 3, 4))(2)(9)
substitute(List(1, 2, 3, 4))(9)(2)
substitute(List(1, 2, 3, 4, 2, 3, 2, 5, 2))(2)(9)
substitute(List())(9)(2)
substitute(List("a", "b", "c", "d", "e", "f"))("a")("string")
substitute(List("a", "b", "c", "d", "e", "f"))("g")("string")
substitute(List("a", "b", "c", "a", "e", "a", "f", "a"))("a")("string")
substitute(List())("a")("string")