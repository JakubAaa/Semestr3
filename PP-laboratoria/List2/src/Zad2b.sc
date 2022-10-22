import scala.annotation.tailrec

def split2[T](list: List[T]): (List[T], List[T]) = {
  @tailrec
  def split(startList: List[T], list1: List[T], list1Quantity: Int, list2: List[T], list2Quantity:Int): (List[T], List[T]) = {
    if (startList == Nil)
      (list1, list2)
    else if (list1Quantity > list2Quantity)
      split(startList.tail, list1, list1Quantity, startList.head :: list2, list2Quantity + 1)
    else
      split(startList.tail, startList.head :: list1, list1Quantity + 1, list2, list2Quantity)
  }
  split(list, List(), 0, List(), 0)
}

split2(List(1,2,3,4,5,6,7,8,9))
split2(List(1,2,3,4,5,6,7,8))
split2(List())