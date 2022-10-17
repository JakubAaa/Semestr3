def listLength[T](list: List[T]): Int = {
  if (list.equals(Nil))
    0
  else
    1 + listLength(list.tail)
}

listLength(List())
listLength(List("String"))
listLength(List(1, 2))
listLength(List('a', 'b', 'c'))
listLength(List(true, false,true, false))
listLength(List(1.11, 2.22, 3.33, 4.44, 5.55))