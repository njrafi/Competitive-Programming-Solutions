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
struct kid
{
    int v, d, p, num;
};
vector<kid> v;
int dour, dour_cry;
int unstable()
{
    for (int i = 0; i < v.size(); i++)
        if (v[i].p < 0)
        {
            dour = i;
            dour_cry = v[i].d;
            return 1;
        }
    return 0;
}
void func()
{
    v.erase(v.begin() + dour);
    for (int i = dour; i < v.size(); i++)
        if (v[i].p >= 0)
            v[i].p -= dour_cry;
}
int main()
{
    // freopen("in.txt","r",stdin);
    int n, cry;
    vi res;
    kid tem;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tem.v >> tem.d >> tem.p;
        tem.num = i;
        v.pb(tem);
    }
    while (v.size())
    {
        res.pb(v[0].num);
        cry = v[0].v;
        v.erase(v.begin());
        for (int i = 0; i < v.size() && cry; i++, cry--)
            v[i].p -= cry;
        while (unstable())
            func();
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
