def count[T](a: T, list: List[T]): Int = {
  if (list.equals(Nil))
    0
  else if (list.head.equals(a))
    1 + count(a, list.tail)
  else
    count(a, list.tail)
}

count('a', List('a', 'b', 'c', 'a', 'd', 'a', 'a'))
count(true, List(false, true, false, true, true, false))
count(false, List())
count(1, List(0, 2, 3, 4))