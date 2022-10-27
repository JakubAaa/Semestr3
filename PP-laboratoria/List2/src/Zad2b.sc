import scala.annotation.tailrec

def split2Tail[T](list: List[T]): (List[T], List[T]) = {
  @tailrec
  def split(list: List[T], list1: List[T], list1Length: Int, list2: List[T], list2Length: Int): (List[T], List[T]) = {
    list match
//      case _ :: t if list1Length == list2Length && t == Nil => (list1, list2)
      case h :: t if list1Length > list2Length => split(t, list1, list1Length, h :: list2, list2Length + 1)
      case h :: t => split(t, h :: list1, list1Length + 1, list2, list2Length)
      case _ => (list1, list2)
  }

  split(list, List(), 0, List(), 0)
}

split2Tail(List(1, 2, 3, 4, 5, 6, 7, 8, 9))
split2Tail(List(1, 2, 3, 4, 5, 6, 7, 8))
split2Tail(List("s1", "s2", "s3", "s4", "s5"))
split2Tail(List("s1", "s2", "s3", "s4"))
split2Tail(List(true, false))
split2Tail(List(true))
split2Tail(List())