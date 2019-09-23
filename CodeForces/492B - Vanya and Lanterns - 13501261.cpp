#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
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
int main()
{
    int n, l, inp;
    double maxd = 0;
    vi v;
    cin >> n >> l;
    while (n--)
    {
        cin >> inp;
        v.pb(inp);
    }
    sort(all(v));
    for (int i = 1; i < v.size(); i++)
        if (v[i] - v[i - 1] > maxd)
            maxd = v[i] - v[i - 1];
    maxd /= 2;
    if (v[0] > maxd)
        maxd = v[0];
    if (l - v[v.size() - 1] > maxd)
        maxd = l - v[v.size() - 1];
    printf("%.10f\n", maxd);
    return 0;
}