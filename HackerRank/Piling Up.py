v = []

def f(i,j,last):
    #print(i,j,last)
    
    while True:
        #print(i,j,last)
        if i>=j:
            return 1

        if v[i]>last or v[j]>last:
            return 0

        if v[i]>=v[j]:
            i = i + 1
            last = v[i-1]
        else:
            j = j - 1
            last = v[j+1]

t = int(input())
for _ in range(t):
    n = int(input())
    v = list ( map(int , input().split()) ) 
    #print(v)
    #v.append(0)
    if f(0,len(v)-1,2**32)==1:
        print('Yes')
    else:
        print('No')