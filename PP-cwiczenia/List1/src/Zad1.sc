def flatten1[T](list: List[List[T]]): List[T] = {
  if(list.equals(Nil))
    Nil
  else
    list.head ::: flatten1(list.tail)
}

flatten1(List(List(1,2,3), List(4,5,6), List(7,8,9)))
flatten1(List(List('a', 'b'), List('c', 'd'), List('e', 'f')))
flatten1(List(List(true), List(false), List(true)))
flatten1(List(List(), List(), List()))
