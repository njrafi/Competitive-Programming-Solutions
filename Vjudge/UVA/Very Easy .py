import sys

for line in sys.stdin:
    n,a = line.split();
    n = int(n)
    a = int(a)
    ans = 0
    for i in range(1,n+1):
        ans += i * pow(a,i)
    print(ans)