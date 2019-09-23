#include <bits/stdc++.h>
#define mod 1000003
#define si 1000005
using namespace std;
long long int f[si];
long long int fact(long long int n)
{
    if (f[n] != -1)
        return f[n];
    f[n] = ((n % mod) * (fact(n - 1) % mod)) % mod;
    return f[n];
}
void fgen()
{
    for (int i = 2; i < si; i++)
        f[i] = -1;
    f[0] = 1;
    f[1] = 1;
    fact(si - 1);
}
long long int bigmod(long long int n, long long int p)
{
    if (p == 0)
        return 1;
    if (p % 2 == 0)
        return ((bigmod(n, p / 2) % mod) * (bigmod(n, p / 2) % mod)) % mod;
    else
        return ((bigmod(n, p / 2) % mod) * (bigmod(n, p / 2) % mod * n % mod)) % mod;
}
int main()
{
    fgen();
    // for(int i=1;i<si;i++)
    // cout << f[i] << endl;
    int t;
    long long int n, k, res;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        res = ((f[n] % mod) * (bigmod(f[n - k], mod - 2) % mod) * (bigmod(f[k], mod - 2) % mod)) % mod;
        printf("Case %d: %lld\n", i, res);
    }
    return 0;
}
