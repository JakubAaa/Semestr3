def lazyZip[A] (list: LazyList[A]): LazyList[(A, A)] =
  list match
    case h1 #:: (t1@(h2 #:: _)) => (h1, h2) #:: lazyZip(t1)
    case _ => LazyList()

lazyZip(LazyList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)).force
lazyZip(LazyList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)).force
lazyZip(LazyList.range(0, 50)).force
lazyZip(LazyList()).force
lazyZip(LazyList.from(11).take(35)).force