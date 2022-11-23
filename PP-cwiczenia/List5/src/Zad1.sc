def lrepeat[A] (k: Int, list: LazyList[A]): LazyList[A] =
  def repeat (counter: Int, list: LazyList[A]): LazyList[A] =
    (counter, list) match
      case (_, LazyList()) => LazyList()
      case (0, _ #:: t) => repeat(k, t)
      case (c, h #:: t) => h #:: repeat(c-1, list)
  repeat(k, list)

lrepeat(3, LazyList(1,2,3,4)).force