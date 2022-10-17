def sqrList[Int](list: List[Int]): List[Int] = {
  if (list.equals(Nil))
    Nil
  else
    list.head * list.head :: sqrList(list.tail)
}

sqrList(List())
sqrList(List(0))
sqrList(List(2))
sqrList(List(1, 2, 3, 4, 5, 6, 7, 8, 9))
