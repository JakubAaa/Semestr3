let rec palindrome = fun(list) ->
  List.rev list = list;;

palindrome([1; 2; 3; 2; 1]);;
palindrome(['k'; 'a'; 'j'; 'a'; 'k']);;
palindrome([true; true; false; true; true; false; true; true]);;
palindrome([1.11; 2.22; 2.22; 1.11]);;
palindrome([1.11; 2.22; 2.22; 1.11; 1.23]);;
palindrome(["String"; "Tez string"]);;