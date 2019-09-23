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
int n, k, ind[20], l, r, x, res = 0, inp[20];
vi v;
void func()
{
    sort(all(v));
    int diff = 0, lsfs;
    lsfs = v[v.size() - 1] - v[0];
    For(i, v.size())
        diff += v[i];
    if (diff >= l && diff <= r && lsfs >= x)
        res++;
}
void comb(int pos, int last)
{
    if (pos > k)
    {
        v.clear();
        for (int i = 1; i <= k; i++)
            v.pb(inp[ind[i]]);
        func();
        return;
    }
    for (int i = last + 1; i <= n - k + pos; i++)
    {
        ind[pos] = i;
        comb(pos + 1, i);
    }
}
int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 1; i <= n; i++)
        cin >> inp[i];
    for (k = 2; k <= n; k++)
        comb(1, 0);
    cout << res << endl;
    return 0;
}
