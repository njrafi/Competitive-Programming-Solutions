#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long long n;
    cin >> n;
    long long s = 1, g = 1;
    for (long long i = 1; i <= n; i++)
    {
        s = (s * 7) % mod;
    }
    for (long long i = 1; i <= 3 * n; i++)
    {
        g = (g * 3) % mod;
    }
    cout << (g - s + mod) % mod;
    return 0;
}