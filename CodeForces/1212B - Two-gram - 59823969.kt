fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
 fun main() {
 var n = readInt()
 var ss = readStrings()
 var s = ss[0]
 var m: MutableMap<String, Int> = mutableMapOf()
 for(i in 0..n-2) {
  var gg = Character.toString(s[i])
  gg += s[i+1]
  m[gg] = m.getOrDefault(gg, 0) + 1
 }
  var ans = ""
 var now = -1
 for( (k,v) in m) {
  if( v > now) {
   ans = k
   now = v
  }
 // println(k)
 // println(v)
 }
 println(ans)
}