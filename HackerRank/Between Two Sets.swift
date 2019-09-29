import Foundation

/*
 * Complete the getTotalX function below.
 */
func getTotalX(a: [Int], b: [Int]) -> Int {
    
    var ans = 0

    for x in 1...100
    {
        var ok = 1

        for i in a
        {
            if (ok==0) { break }
            if(x % i > 0 )
            {
                ok = 0
                break
            }
        }

        for i in b
        {
            if (ok==0) { break }
            if(i % x > 0)
            {
                ok = 0
                break
            }
        }
        if( ok > 0) { ans += 1}

    }

    return ans

}

let fileName = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: fileName, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: fileName)!

guard let nmTemp = readLine() else { fatalError("Bad input") }
let nm = nmTemp.split(separator: " ").map{ String($0) }

guard let n = Int(nm[0].trimmingCharacters(in: .whitespacesAndNewlines))
else { fatalError("Bad input") }

guard let m = Int(nm[1].trimmingCharacters(in: .whitespacesAndNewlines))
else { fatalError("Bad input") }

guard let aTemp = readLine() else { fatalError("Bad input") }
let a: [Int] = aTemp.split(separator: " ").map {
    if let aItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return aItem
    } else { fatalError("Bad input") }
}

guard a.count == n else { fatalError("Bad input") }

guard let bTemp = readLine() else { fatalError("Bad input") }
let b: [Int] = bTemp.split(separator: " ").map {
    if let bItem = Int($0.trimmingCharacters(in: .whitespacesAndNewlines)) {
        return bItem
    } else { fatalError("Bad input") }
}

guard b.count == m else { fatalError("Bad input") }

let total = getTotalX(a: a, b: b)

fileHandle.write(String(total).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)
