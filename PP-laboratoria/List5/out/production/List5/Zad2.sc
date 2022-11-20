def skipTakeL[A] (startList: LazyList[A]): LazyList[A] =
  def skip (list: LazyList[A], currentIndex: Int, nextIndexToAdd: Int, multiplier: Int): LazyList[A] =
    list match
      case h #:: t if currentIndex == nextIndexToAdd => h #:: skip(t, currentIndex + 1, nextIndexToAdd + 2 * multiplier, multiplier + 1)
      case _ #:: t => skip(t, currentIndex + 1, nextIndexToAdd, multiplier)
      case LazyList() => LazyList()

  skip(startList, 0, 1, 1)

//skipTakeL(LazyList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22)).force
//skipTakeL(LazyList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)).toList
skipTakeL(LazyList(-5, -4, -3, -2 - 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)).toList
//skipTakeL(LazyList())
//skipTakeL(LazyList("a", "b", "c", "d", "e")).force
