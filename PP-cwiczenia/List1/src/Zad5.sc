def palindrome[T](list: List[T]): Boolean = {
  if (list.reverse.equals(list))
    true
  else
    false
}

palindrome(List(1,2,3,2,1))
palindrome(List('k', 'a', 'j', 'a', 'k'))
palindrome(List(true, true, false, true, true, false, true, true))
palindrome(List(1.11, 2.22, 2.22, 1.11))
palindrome(List(1.11, 2.22, 2.22, 1.11, 1.23))
palindrome(List("String", "Tez string"))