let calculateRow array sum =
  let i = ref 0 in
  let temp = ref 1 in 
  let previousValue = ref 0 in 

  while !i < Array.length array - 1 do
    previousValue := array.(!i + 1);

    if sum 
      then array.(!i + 1) <- !temp + array.(!i + 1)
    else
      array.(!i + 1) <- !temp - array.(!i + 1);
    
    temp := !previousValue;
    i := !i + 1;
  done;
Array.append array [|1|];;

let modifiedPascal rowNumber =
  let resultArray = ref [||] in
  let currentRow = ref (-1) in
  let sumBoolean = ref true in 

  while !currentRow < rowNumber do 
    resultArray := calculateRow !resultArray !sumBoolean;
    sumBoolean := not !sumBoolean; 
    currentRow := !currentRow + 1; 
  done;
resultArray;;

modifiedPascal(-11);;
modifiedPascal(0);;
modifiedPascal(1);;
modifiedPascal(2);;
modifiedPascal(3);;
modifiedPascal(4);;
modifiedPascal(5);;
modifiedPascal(6);;
modifiedPascal(7);;
modifiedPascal(8);;