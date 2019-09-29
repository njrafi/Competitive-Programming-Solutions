ac = list(map(int,input().split()))
ex = list(map(int,input().split()))

if(ac[2] > ex[2]):
    print("10000")
elif(ac[2] < ex[2]):
    print("0")
else:
    if(ac[1] > ex[1]):
        print(500 * (ac[1] - ex[1]))
    elif(ac[1] < ex[1]):
        print("0")
    else:
        if(ac[0] > ex[0]):
            print(15 * (ac[0] - ex[0]))
        else:
            print("0")
    