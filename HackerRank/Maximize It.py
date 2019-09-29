v = []
ans = 0

def f(pos,sum):
    if pos==len(v):
        #print(sum%m)
        global ans
        ans = max(ans , sum % m)
        #print(m)
        return
    
    for i in range(1,len(v[pos])):
        nsum = (sum + v[pos][i] * v[pos][i])
        f(pos+1,nsum)

k,m = input().split()
k = int(k)
m = int(m)


for i in range(k):
    v.append(list(map(int,input().split())))
    #print(v[i])
    

f(0,0)
print(ans)