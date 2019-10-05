# Count the tree uva - 10007

dp = []


for i in range(305):
    dp.append(0)


def f(n):
    if(n<2):
        return 1
    if(dp[n]>0):
        return dp[n]
    ans = ( 4 * (n-1) + 2) * f(n-1) * n
    ans = ans // (n+1)
    dp[n] = ans
    return ans




while(True):
    n = int(input())
    if(n==0):
        break
    print(f(n))