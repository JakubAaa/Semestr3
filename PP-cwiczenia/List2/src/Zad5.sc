import scala.annotation.tailrec

@tailrec
def initSegment[T](list1: List[T], list2: List[T]): Boolean = {
  list1 match
    case Nil => true
    case h :: t if list2 != Nil && h == list2.head => initSegment(t, list2.tail)
    case _ => false
}

initSegment(List(1,2,3,4,5), List(1,2,3,4,5,6,7,8))
initSegment(List(1,2,3,4,5), List(1,2))
initSegment(List(3,2,1), List(1,2,3,4,5,6))
initSegment(List(), List())
initSegment(List(1,2,3,4), List(1,2,3,4))
