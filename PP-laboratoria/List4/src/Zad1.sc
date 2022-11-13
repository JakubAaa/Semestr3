import scala.annotation.tailrec
import scala.Array

type Change = (Int, Char)
type Snapshot = List[Change]

sealed trait snapshotsTree[+A]
case object Empty extends snapshotsTree[Nothing]
case class Node[+A](snapshot: Snapshot, tree: snapshotsTree[A]) extends snapshotsTree[A]

def createSnapshot(newString: String, startIndex: Int): Snapshot =
  val charList: List[Char] = newString.toList
  for (x <- List.range(0, charList.length)) yield new Change(startIndex + x, charList(x))

def insertSubstring(oldSnapshot: Snapshot, substring: String, index: Int): Snapshot =
  if(index >= oldSnapshot.length)
    createSnapshot(substring, index)
  else
    def insert(currentIndex: Int, list: Snapshot): Snapshot =
      list match
        case h :: t if currentIndex == index => createSnapshot(substring, index) ::: insert(currentIndex + index + 1, h :: t)
        case _ :: t if currentIndex < index => insert(currentIndex + 1, t)
        case h :: t if currentIndex > index => List(new Change(h._1 + index - 1, h._2)) ::: insert(currentIndex + index + 1, t)
        case _ => Nil
    insert(0, oldSnapshot)

def deleteSubstringByIndex(indexFrom: Int, indexTo: Int): Snapshot =
  for (x <- List.range(indexFrom, indexTo + 1)) yield
    new Change(x, 0)
@tailrec
def getChangeByIndex(index: Int, changes: Snapshot): Change =
  changes match
    case h :: _ if h._1 == index => h
    case _ :: t => getChangeByIndex(index, t)
    case _ => null

@tailrec
def getBiggestIndex(changes: Snapshot): Int =
  if(changes == null || changes.isEmpty)
    0
  else
    val sortedList = changes sortBy (_._1)
    val reversedSortedList = sortedList.reverse
    if reversedSortedList.head._2 == 0 then getBiggestIndex(reversedSortedList.tail) else reversedSortedList.head._1

def applySnapshot(old: Snapshot, changes: Snapshot): Snapshot =
  val theBiggestIndex = getBiggestIndex(changes)
  val range = if theBiggestIndex > old.length then theBiggestIndex + 1 else old.length
  for (x <- List.range(0, range)) yield
    val elem = getChangeByIndex(x, changes)
      if (elem != null && elem._2 == 0)
        null
      else if (elem != null)
        elem
      else if (x >= old.length)
        new Change(x, ' ')
      else
        old(x)

@tailrec
def applySnapshotsInTree[A](tree: snapshotsTree[A], snapshot: Snapshot): Snapshot =
  tree match
    case Node(oldSnapshot, Empty) => applySnapshot(oldSnapshot, snapshot)
    case Node(oldSnapshot, Node(newSnapshot, bt)) => applySnapshotsInTree(Node(applySnapshot(oldSnapshot, newSnapshot), bt), snapshot)
    case _ => null

def review[A](tree: snapshotsTree[A], snapshot: Snapshot) =
  val finalSnapShot = applySnapshotsInTree(tree, snapshot)
  val finalList = finalSnapShot.map(e => if e == null then "" else e._2)
  finalList.mkString

val exampleTree = Node(createSnapshot("Ala ma kota", 0),
                      Node(insertSubstring(createSnapshot("Ala ma kota", 0), "i psa tezzzzzzz", 12),
                          Node(deleteSubstringByIndex(21, 27),
                              Node(List(new Change(7, 'K'), new Change(25, ';'), new Change(26, ')'), new Change(24, ' ')), Empty
                                  )
                              )
                          )
                      )

review(exampleTree, List((14, 'P')))