def find[T](list: List[T], toFind: T): List[Int] = {
  def findIndex(list: List[T], toFind: T, index: Int): List[Int] =
    list match
      case h :: t if h == toFind => index :: findIndex(t, toFind, index + 1)
      case h :: t => findIndex(t, toFind, index + 1)
      case _ => Nil

  findIndex(list, toFind, 0)
}

find(List(1,2,6,3,4,5,6,7,8), 6)
find(List(), 6)
find(List(1,2,3,3,3,3), 3)
find(List(1,2,3,3,3,3), -1)
