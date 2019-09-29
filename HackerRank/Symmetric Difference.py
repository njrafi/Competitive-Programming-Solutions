n = int(input())
s1 = set(map(int,input().split()))
n = int(input())
s2 = set(map(int,input().split()))

s = s1.union(s2).difference(s1.intersection(s2))
v = list(s)
v.sort()
for i in v:
    print(i)