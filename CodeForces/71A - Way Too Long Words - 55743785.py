n = input('')
b = []
while n > 0:
        a = raw_input('')
        b.append(a)
        n = n-1
t = 0
while t < len(b):
    if len(b[t]) > 10:
        length = len(b[t])-2
        length = str(length)
        c = b[t]
        print c[0] + length + c[len(c)-1]
    else:
        print b[t]
    t = t+1
