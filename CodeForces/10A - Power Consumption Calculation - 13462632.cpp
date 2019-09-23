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
    int n, p1, p2, p3, t1, t2, l, r, pr = 0, res = 0, rem;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    For(i, n)
    {
        cin >> l >> r;
        res += (r - l) * p1;
        if (!i)
            pr = l;
        rem = l - pr;
        if (rem <= t1)
            res += rem * p1;
        else if (rem > t1 && rem <= (t1 + t2))
            res += t1 * p1 + (rem - t1) * p2;
        else
            res += t1 * p1 + t2 * p2 + (rem - t1 - t2) * p3;
        pr = r;
    }
    cout << res << endl;
    return 0;
}
