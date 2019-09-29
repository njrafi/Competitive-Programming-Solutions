# Complete the solve function below.
def solve(s):
    #s = list(s)
    gg = ''
    for i in range(len(s)):
        if i==0 or s[(i-1)]==' ':
            if(s[i].islower()):
                gg += s[i].upper()
            else:
                gg += s[i]
        else:
            gg += s[i]
    #s = str(s)
    return gg