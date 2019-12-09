
func cutRod(p: [Int], n: Int) -> Int {
  if n == 0 {
    return 0
  }
  var q = -10000000000
  for i in 1..<n {
    q = p[i] + max(q, cutRod(p: p, n: n-i)) 
  }
  print("cutRod(p: \(p), n: \(n), q: \(q))")
  return q
}

let p = [1, 2, 3]
let n = 3
let r = cutRod(p: p, n: n)
print("r: \(r)")

