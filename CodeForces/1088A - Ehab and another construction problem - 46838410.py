x = int(input())
for a in range(1,x+1):
    for b in range(1,x+1):
        if( a % b == 0 and a * b > x and a/b < x ) :
            print(a,b)
            exit(0)
 print(-1)