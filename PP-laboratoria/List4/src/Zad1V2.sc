import scala.annotation.tailrec

sealed trait operation[+A]
case class CreateString[+A] (value: String) extends operation[A]
case class InsertSubstring[+A] (index: Int, value: String) extends operation[A]
case class DeleteSubstring[+A] (index: Int) extends operation[A]
case class MoveSubstring[+A] (sourceIndex: Int, destinationIndex: Int) extends operation[A]

sealed trait snapshotsTree[+A]
case object Empty extends snapshotsTree[Nothing]
case class Node[+A] (operation: operation[A], tree: snapshotsTree[A]) extends snapshotsTree[A]

def createNewString (value: String): List[String] =
  value.split(" ").toList

def insertSubstring (list: List[String], index: Int, value: String): List[String] =
  if (list == null || index < 0)
    null
  else
    def insert (list: List[String], currentIndex: Int): List[String] =
      list match
        case h :: t if currentIndex == index => value :: h :: insert(t, currentIndex + 2)
        case h :: t => h :: insert(t, currentIndex + 1)
        case _ if currentIndex <= index => value :: Nil
        case _ => Nil

    insert(list, 0)

def deleteSubstring (list: List[String], index: Int): List[String] =
  if (list == null || index < 0 || index >= list.length)
    null
  else
    def delete (list: List[String], currentIndex: Int): List[String] =
      list match
        case _ :: t if currentIndex == index => delete(t, currentIndex + 1)
        case h :: t => h :: delete(t, currentIndex + 1)
        case _ => Nil

    delete(list, 0)

def moveSubstring (list: List[String], sourceIndex: Int, destinationIndex: Int): List[String] =
  if (list == null || sourceIndex < 0 || sourceIndex >= list.length || destinationIndex < 0)
    null
  else if (sourceIndex == destinationIndex)
    list
  else
    def getPartOfList (list: List[String], indexFrom: Int, indexTo: Int, currentIndex: Int): List[String] =
      list match
        case _ :: t if currentIndex < indexFrom => getPartOfList(t, indexFrom, indexTo, currentIndex + 1)
        case h :: t if currentIndex >= indexFrom && currentIndex < indexTo => h :: getPartOfList(t, indexFrom, indexTo, currentIndex + 1)
        case _ => Nil

    if (sourceIndex < destinationIndex)
      getPartOfList(list, 0, sourceIndex, 0) :::
        getPartOfList(list, sourceIndex + 1, destinationIndex + 1, 0) :::
        list(sourceIndex) :: getPartOfList(list, destinationIndex + 1, list.length, 0)
    else
      getPartOfList(list, 0, destinationIndex, 0) :::
        list(sourceIndex) :: getPartOfList(list, destinationIndex, sourceIndex, 0) :::
        getPartOfList(list, sourceIndex + 1, list.length, 0)

def applyOperation[A] (operation: operation[A], oldVersion: List[String]): List[String] =
  operation match
    case CreateString(value) => createNewString(value)
    case InsertSubstring(index, value) => insertSubstring(oldVersion, index, value)
    case DeleteSubstring(index) => deleteSubstring(oldVersion, index)
    case MoveSubstring(sIndex, dIndex) => moveSubstring(oldVersion, sIndex, dIndex)

def review[A] (root: snapshotsTree[A], newOperation: operation[A]): String =
  @tailrec
  def reviewRec (tree: snapshotsTree[A], currentListOfStrings: List[String]): List[String] =
    tree match
      case Empty => currentListOfStrings
      case null => null
      case Node(op, tr) => reviewRec(tr, applyOperation(op, currentListOfStrings))

  val finalList = applyOperation(newOperation, reviewRec(root, List()))
  if (finalList == null)
    null
  else
    finalList.mkString(" ")

//TESTS - createNewString
createNewString("Ala")
val manyElementsList = createNewString("Ala ma kota")

//TESTS - insertSubstring
insertSubstring(List(), 0, "Ola")
insertSubstring(List(), -5, "Ola")
insertSubstring(List(), 5, "Ola")

insertSubstring(manyElementsList, -5, "Ola")
insertSubstring(manyElementsList, 0, "Ola")
insertSubstring(manyElementsList, 1, "Ola")
insertSubstring(manyElementsList, 3, "Ola")
insertSubstring(manyElementsList, 7, "Ola")

//TESTS - deleteSubstring
deleteSubstring(List(), -5)
deleteSubstring(List(), 0)
deleteSubstring(List(), 5)

deleteSubstring(manyElementsList, -5)
deleteSubstring(manyElementsList, 0)
deleteSubstring(manyElementsList, 1)
deleteSubstring(manyElementsList, 2)
deleteSubstring(manyElementsList, 5)

//TESTS - moveSubstring
moveSubstring(List(), 0, 1)
moveSubstring(List(), -5, 1)

moveSubstring(manyElementsList, -5, 1)
moveSubstring(manyElementsList, 1, -1)
moveSubstring(manyElementsList, -1, -1)
moveSubstring(manyElementsList, 0, 0)
moveSubstring(manyElementsList, 0, 1)
moveSubstring(manyElementsList, 0, 5)
moveSubstring(manyElementsList, 2, 0)
moveSubstring(manyElementsList, 2, 1)

//TESTS - SnapshotTree
val exampleTree1 = Node(CreateString("Ala Ala kota ma"),              //Ala Ala kota ma
  Node(InsertSubstring(3, "psa"),                 //Ala Ala kota psa ma
    Node(InsertSubstring(3, "i"),               //Ala Ala kota i psa ma
      Node(MoveSubstring(5, 2), Empty         //Ala Ala ma kota i psa
      )
    )
  )
)
review(exampleTree1, DeleteSubstring(0))                               //Ala ma kota i psa

val exampleTree2 = Node(CreateString("Ala ma kota"),
  Node(InsertSubstring(-1, "psa"), Empty
  )
)
review(exampleTree2, DeleteSubstring(0))

val exampleTree3 = Node(CreateString("Ala ma kota"),
  Node(InsertSubstring(1, "psa"), Empty
  )
)
review(exampleTree3, DeleteSubstring(-5))