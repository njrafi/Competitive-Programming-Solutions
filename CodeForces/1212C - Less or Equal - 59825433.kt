fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
 fun main() {
 var (n , k) = readInts()
 var a = readInts()
 var b = ArrayList<Int>(a)
 b.sort()
 k--;
 if( k < 0 ) {
  if(b[0] == 1) {
   println(-1)
  } else {
   println(1)
  }
 }
 else if ( k >= n ) {
  println(-1)
 } else if( k == n - 1) {
  println(b[k])
 } else if( b[k+1] > b[k] ) {
  println(b[k])
 } else {
  println(-1)
 }
}