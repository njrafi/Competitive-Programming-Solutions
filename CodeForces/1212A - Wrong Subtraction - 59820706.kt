fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
 fun main() {
 var (n, k) = readInts()
// println(n)
// println(k)
 for( i in 1..k) {
  if (n % 10 > 0) {
   n -= 1
  } else {
   n /= 10
  }
 }
 println(n)
}