def calculateRow (array: Array[Int], sum: Boolean): Array[Int] = {
  var i = 0
  var temp = 1
  var previousValue = 0

  while (i < array.length - 1) {
    previousValue = array(i + 1)

    if (sum)
      array(i + 1) = temp + array(i + 1)
    else
      array(i + 1) = temp - array(i + 1)

    temp = previousValue
    i += 1
  }

  array :+ 1
}

def modifiedPascal (rowNumber: Int): Array[Int] = {
  var resultArray = Array[Int]()
  var currentRow = -1
  var sumBoolean = true

  while (currentRow < rowNumber) {
    resultArray = calculateRow(resultArray, sumBoolean)
    sumBoolean = !sumBoolean
    currentRow += 1
  }

  resultArray
}

modifiedPascal(-11)
modifiedPascal(0)
modifiedPascal(1)
modifiedPascal(2)
modifiedPascal(3)
modifiedPascal(4)
modifiedPascal(5)
modifiedPascal(6)
modifiedPascal(7)
modifiedPascal(8)