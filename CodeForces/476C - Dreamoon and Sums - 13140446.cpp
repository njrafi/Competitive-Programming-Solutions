#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    long long int a, b, res;
    cin >> a >> b;
    res = (((a * (a + 1) / 2 % mod) * b % mod + a) % mod * (b * (b - 1) / 2 % mod)) % mod;
    cout << res << endl;
    return 0;
}
