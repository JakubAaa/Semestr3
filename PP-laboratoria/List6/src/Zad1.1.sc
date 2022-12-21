import scala.annotation.tailrec

def modifiedPascalF (rowNumber: Int): List[Int] = {
  @tailrec
  def pascal (currentRow: Int, list: List[Int], sum: Boolean): List[Int] = {
    if (currentRow == rowNumber)
      list
    else
      def listRec (currentList: List[Int]): List[Int] = {
        currentList match
          case h1 :: (t@h2 :: _) if sum => h1 + h2 :: listRec(t)
          case h1 :: (t@h2 :: _) => h1 - h2 :: listRec(t)
          case h :: _ => h :: Nil
          case _ => Nil
      }

      pascal(currentRow + 1, 1 :: listRec(list), !sum)
  }

  if (rowNumber < 0)
    List()
  else
    pascal(-1, List(), true)
}

modifiedPascalF(-1)
modifiedPascalF(0)
modifiedPascalF(1)
modifiedPascalF(2)
modifiedPascalF(3)
modifiedPascalF(4)
modifiedPascalF(5)
modifiedPascalF(6)
modifiedPascalF(7)
modifiedPascalF(8)