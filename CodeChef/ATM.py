a,b = raw_input().split()

a = float(a)
b = float(b)

if a%5==0 and a+0.5 <= b:
    print b-a-0.5
else:
    print b
