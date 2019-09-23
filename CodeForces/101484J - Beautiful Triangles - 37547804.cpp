#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll a, b, c, ans = 0;
    cin >> a >> b;
    if (a + a > b && a + a - b >= ans)
    {
        c = a;
        ans = a + a - b;
    }
    if (a + b > b && a >= ans)
    {
        c = b;
        ans = a;
    }
    cout << c << endl;
}