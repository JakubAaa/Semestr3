def split2Rec[T](startList: List[T]): (List[T], List[T]) = {
  def addToList1(tail: List[T], toAdd: T, pair: (List[T], List[T]), list1Length: Int, list2Length: Int): (List[T], List[T]) = {
    val (list1, list2) = split(tail, pair, list1Length + 1, list2Length)
    (toAdd :: list1, list2)
  }

  def addToList2(tail: List[T], toAdd: T, pair: (List[T], List[T]), list1Length: Int, list2Length: Int): (List[T], List[T]) = {
    val (list1, list2) = split(tail, pair, list1Length, list2Length + 1)
    (list1, toAdd :: list2)
  }

  def split(list: List[T], pair: (List[T], List[T]), list1Length: Int, list2Length: Int): (List[T], List[T]) = {
    list match
//      case _ :: t if t == Nil && list1Length == list2Length => pair
      case h :: t if list1Length > list2Length => addToList2(t, h, pair, list1Length, list2Length)
      case h :: t => addToList1(t, h, pair, list1Length, list2Length)
      case _ => pair
  }

  split(startList, (List(), List()), 0, 0)
}

split2Rec(List(1, 2, 3, 4, 5, 6, 7, 8, 9))
split2Rec(List(1, 2, 3, 4, 5, 6, 7, 8))
split2Rec(List("s1", "s2", "s3", "s4", "s5"))
split2Rec(List("s1", "s2", "s3", "s4"))
split2Rec(List(true, false))
split2Rec(List(true))
split2Rec(List())