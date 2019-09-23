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
int main()
{
    int n, inp;
    vi v1, v2, v3;
    v1.pb(0);
    cin >> n;
    For(i, n - 1)
    {
        cin >> inp;
        v1.pb(inp);
    }
    For(i, n - 1)
    {
        cin >> inp;
        v2.pb(inp);
    }
    v2.pb(0);
    reverse(all(v2));
    For(i, n)
    {
        cin >> inp;
        v3.pb(inp);
    }
    for (int i = 1; i < v1.size(); i++)
    {
        v1[i] += v1[i - 1];
        v2[i] += v2[i - 1];
    }
    reverse(all(v2));
    int res = 1000000;
    For(i, n)
        For(j, n) if (i != j)
            res = min(res, v1[i] + v2[i] + v3[i] + v1[j] + v2[j] + v3[j]);
    cout << res << endl;
    return 0;
}
