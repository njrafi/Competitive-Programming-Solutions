t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print("Not prime")
        continue
    elif n == 2:
        print("Prime")
        continue
    ok = 1
    st = 2
    while st * st <= n:
        if n%st==0:
            ok = 0
        st += 1
    if ok==1:
        print("Prime")
    else:
        print("Not prime")