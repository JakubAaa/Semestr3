def swap2[T](list: List[T]): List[T] = {
  if(list.equals(Nil))
    Nil
  else if(list.tail.equals(Nil))
    list.head :: Nil
  else
    list.tail.head :: list.head :: swap2(list.tail.tail)
}

swap2(List()) //expect: ()
swap2(List(1, 2, 3, 4, 5)) //expect: (2,1,4,3,5)
swap2(List(1.11, 2.22, 3.33, 4.44, 5.55, 6.66)) // expect: (2.22,1.11,4.44,3.33,6.66,5.55)
swap2(List("a", "b", "c", "d", "e", "f")) // expect: (b,a,d,c,f,e)
swap2(List(true, false, true, false, false)) // expect: (false,true,false,true,false)