#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef vector<int> vi;
typedef set<int> si;
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mod 1e9 + 7
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
int main()
{
    int n, k, skill = 0, inp;
    vi v;
    cin >> n >> k;
    For(i, n)
    {
        cin >> inp;
        v.pb(inp);
        skill += v[i] / 10;
        v[i] = 10 - v[i] % 10;
    }
    sort(all(v));
    for (int i = 0; k && i < v.size(); i++)
    {
        if (v[i] <= k)
        {
            skill++;
            k -= v[i];
        }
    }
    if (k)
        skill += k / 10;
    if (skill > n * 10)
        skill = n * 10;
    cout << skill << endl;
    return 0;
}
