def curry3[A,B,C,D](f: (A,B,C)=>D) =
  (x:A) => (y:B) => (z:C) => f(x,y,z)

def unCurry3[A,B,C,D](f: A=>B=>C=>D) =
  (x:A, y:B, z:C) => f(x)(y)(z)

