def substitute[T](list: List[T], a: T, b: T): List[T] = {
  if (list.equals(Nil))
    Nil
  else if(list.head.equals(a))
    b :: substitute(list.tail, a, b)
  else
    list.head :: substitute(list.tail, a, b)
}

substitute(List(), 2, 9) //expect: ()
substitute(List(1, 2, 3, 4, 2), 2, 9) //expect: (1,9,3,4,9)
substitute(List("a", "b", "c", "d", "a"), "a", "e") //expect: (e,b,c,d,e)
substitute(List('a', 'c', 'c', 'c', 'a'), 'c', 'f') //expect: (a,f,f,f,a)
substitute(List(true, false, false, true, true), true, false) //expect: (false,false,false,false,false)