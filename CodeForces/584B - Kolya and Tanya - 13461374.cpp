#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> si;
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
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
    long long int inp, res1 = 1, res2 = 1, tem, ans;
    cin >> inp;
    tem = inp * 3;
    while (tem--)
        res1 = (res1 % mod * 3) % mod;
    while (inp--)
        res2 = (res2 % mod * 7) % mod;
    ans = res1 - res2;
    if (ans < 0)
        ans += mod;
    cout << ans << endl;
    return 0;
}
