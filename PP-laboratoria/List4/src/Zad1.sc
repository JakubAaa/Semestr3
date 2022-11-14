import scala.annotation.tailrec
import scala.Array

type Change = (Int, Char)
type Snapshot = List[Change]

sealed trait snapshotsTree[+A]
case object Empty extends snapshotsTree[Nothing]
case class Node[+A](snapshot: Snapshot, tree: snapshotsTree[A]) extends snapshotsTree[A]

def createSnapshot(newString: String, startIndex: Int): Snapshot =
  val charList: List[Char] = newString.toList
  for (x <- List.range(0, charList.length)) yield (startIndex + x, charList(x))

def insertSubstring(previousString: String, substring: String, index: Int): Snapshot =
  val oldSnapshot = createSnapshot(previousString, 0)
  val oldSnapshotLength = oldSnapshot.length
  if(index >= oldSnapshotLength)
    createSnapshot(substring, oldSnapshotLength)
  else
    def insert(currentIndex: Int, snapshot: Snapshot): Snapshot =
      snapshot match
        case h :: t if currentIndex == index => createSnapshot(substring, index) ::: insert(currentIndex + index + 1, h :: t)
        case _ :: t if currentIndex < index => insert(currentIndex + 1, t)
        case h :: t if currentIndex > index => (h._1 + index - 1, h._2) :: insert(currentIndex + index + 1, t)
        case _ => Nil
    insert(0, oldSnapshot)

def deleteSubstringByIndex(indexFrom: Int, indexTo: Int): Snapshot =
  for (x <- List.range(indexFrom, indexTo + 1)) yield
    (x, 0)

def moveSubstring(previousString: String, sourceIndex: Int, destinationIndex: Int, length: Int): Snapshot =
  val oldSnapshot = createSnapshot(previousString, 0)
  val oldSnapshotLength = oldSnapshot.length
  if(sourceIndex >= oldSnapshotLength || destinationIndex >= oldSnapshotLength)
    null
  else if(sourceIndex == destinationIndex)
    List()
  else if(sourceIndex > destinationIndex)
    for
  else
    List()
@tailrec
def checkSnapshot(oldSnapshotLength: Int, snapshot: Snapshot): Boolean =
  snapshot match
    case h :: _ if h._1 < 0 => false
    case h :: _ if h._2 == 0 && h._1 >= oldSnapshotLength => false
    case _ :: t => checkSnapshot(oldSnapshotLength, t)
    case _ => true
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
  val oldLength = old.length
  if(!checkSnapshot(oldLength, changes))
    null
  else
    val theBiggestIndex = getBiggestIndex(changes)
    val range = if theBiggestIndex > oldLength then theBiggestIndex + 1 else oldLength
    for (x <- List.range(0, range)) yield
      val elem = getChangeByIndex(x, changes)
        if (elem != null && elem._2 == 0)
          null
        else if (elem != null)
          elem
        else if (x >= oldLength)
          null
        else
          old(x)

@tailrec
def applySnapshotsInTree[A](tree: snapshotsTree[A], snapshot: Snapshot): Snapshot =
  tree match
    case Node(_, Node(null, _)) => null
    case Node(null, _) => null
    case Node(oldSnapshot, Empty) => applySnapshot(oldSnapshot, snapshot)
    case Node(oldSnapshot, Node(newSnapshot, tree)) => applySnapshotsInTree(Node(applySnapshot(oldSnapshot, newSnapshot), tree), snapshot)
    case _ => null

def review[A](tree: snapshotsTree[A], snapshot: Snapshot) =
  val finalSnapShot = applySnapshotsInTree(tree, snapshot)
  if(finalSnapShot == null)
    Empty
  else
    val finalList = finalSnapShot.map(e => if e == null then "" else e._2)
    finalList.mkString

val exampleTree = Node(createSnapshot("Ala ma kota ", 0),
                      Node(insertSubstring("Ala ma kota " , "i psa tezzzzzzz", 12),
                          Node(deleteSubstringByIndex(21, 26),
                              Node(moveSubstring("Ala ma kota i psa tez", 12, 12, 2), Empty
                                  )
                              )
                          )
                      )

review(exampleTree, List((14, 'P'), (7, 'K'), (25, ';'), (26, ')'), (24, ' ')))