# How many tree - 10303



from sys import stdin

dp = []


for i in range(1002):
    dp.append(0)


def f(n):
    if(n<2):
        return 1
    if(dp[n]>0):
        return dp[n]
    ans = ( 4 * (n-1) + 2) * f(n-1) 
    ans = ans // (n+1)
    dp[n] = ans
    return ans




lines = stdin.readlines()
for line in lines:
    n = int(line)
    print(f(n))