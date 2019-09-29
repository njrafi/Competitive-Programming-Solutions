input()
v = list(map(int , input().split()))
a = set(map(int , input().split()))
b = set(map(int , input().split()))
ans = 0
for i in v:
    if i in a:
        ans = ans + 1
    if i in b:
        ans = ans - 1
print(ans)