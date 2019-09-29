t = int(input())
v = []
cnt = {}
for _ in range(t):
    s = input()
    if s in cnt:
        cnt[s] = cnt[s] + 1
    else:
        cnt[s] = 1
        v.append(s)
print(len(v))
for i in v:
    print("%d " %cnt[i],end = '')