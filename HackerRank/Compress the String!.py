s = input()
last = s[0]
cnt = 0
v = []

for i in s:
    if i == last:
        cnt = cnt + 1
    else:
        v.append((cnt,ord(last)-ord('1')+1))
        cnt = 1
        last = i
        
v.append((cnt,ord(last)-ord('1')+1))

print(*v)