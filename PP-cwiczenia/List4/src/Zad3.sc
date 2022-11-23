sealed trait BT[A]
case class Empty[A] () extends BT[A]
case class Node[A] (elem: A, left: BT[A], right: BT[A]) extends BT[A]

val tt = Node(
  1,
  Node(2, Node(4, Empty(), Empty()), Empty()),
  Node(3, Node(5, Empty(), Node(6, Empty(), Empty())), Empty())
)

def breadthBt[A] (tree: BT[A]): List[A] =
  def breadth (queue: List[BT[A]]): List[A] =
    queue match
      case Nil => Nil
      case h :: t =>
        h match
          case Node(v, l, r) => v :: breadth(t ::: List(l, r))
          case Empty() => breadth(t)

  breadth(List(tree))

breadthBt(tt)