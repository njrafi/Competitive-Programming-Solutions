#include <bits/stdc++.h>
#define sf(n) scanf("%d", &n)
#define pb push_back
#define vi vector<i64>
#define i64 long long int
using namespace std;
int main()
{
    int t, n, inp;
    sf(t);
    while (t--)
    {
        vi v;
        sf(n);
        while (n--)
        {
            sf(inp);
            v.pb(inp);
        }
        sort(v.begin(), v.end());
        i64 x = (i64)v[0] * v.back();
        set<i64> s;
        for (i64 i = 1; i < sqrt(x) + 5; i++)
            if (x % i == 0)
            {
                s.insert(i);
                s.insert(x / i);
            }
        v.pb(1);
        v.pb(x);
        vi w;
        for (auto it : s)
            w.pb(it);
        sort(v.begin(), v.end());
        if (v == w)
            cout << x << endl;
        else
            cout << -1 << endl;
    }
}