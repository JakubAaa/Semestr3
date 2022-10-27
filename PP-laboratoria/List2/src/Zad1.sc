def find[T](list: List[T])(toFind: T): List[Int] = {
  def findIndex(list: List[T], toFind: T, index: Int): List[Int] =
    list match
      case h :: t if h == toFind => index :: findIndex(t, toFind, index + 1)
      case _ :: t => findIndex(t, toFind, index + 1)
      case _ => Nil

  findIndex(list, toFind, 0)
}

val find123 = find(List(1, 2, 3))
val find1212121212 = find(List(1, 2, 1, 2, 1, 2, 1, 2, 1, 2))

find (List(1, 2, 6, 3, 4, 5, 6, 7, 8))(6)
find(List())(6)
find(List(1, 2, 4, 5, 6, 7, 8))(3)
find(List("a", "b", "c", "a", "a"))("a")
find(List())("a")
find(List("b", "c", "d", "e", "f"))("a")

find123(2)
find123(5)
find1212121212(1)
find1212121212(3)