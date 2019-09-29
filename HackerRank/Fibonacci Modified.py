gg = []
gg.append(0);
t1,t2,n = input().split()
t1 = int(t1)
t2 = int(t2)
n = int(n)
gg.append(t1)
gg.append(t2)

for i in range(3,21):
    gg.append( gg[i-2] + gg[i-1] * gg[i-1])

print(gg[n])
    