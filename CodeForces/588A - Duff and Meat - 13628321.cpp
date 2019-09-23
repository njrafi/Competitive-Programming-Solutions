#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define i64 long long
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
#define ff first
#define ss second
#define clr(a) memset(a, -1, sizeof(a))
#define rset(a) memset(a, 0, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "r", stdin)
int main()
{
    int n, l_price, meat, price, res = 0;
    cin >> n;
    n--;
    cin >> meat >> price;
    l_price = price;
    res += l_price * meat;
    while (n--)
    {
        cin >> meat >> price;
        if (price < l_price)
            l_price = price;
        res += l_price * meat;
    }
    cout << res << endl;
    return 0;
}
