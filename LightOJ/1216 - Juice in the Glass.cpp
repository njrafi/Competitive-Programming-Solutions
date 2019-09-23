#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main()
{
    int t;
    double r1, r2, h, p, ans;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> r1 >> r2 >> h >> p;
        r1 = p * (r1 - r2) / h + r2;
        h = p;
        ans = pi * h * (r1 * r1 + r2 * r2 + r1 * r2) / 3;
        printf("Case %d: %.9f\n", i, ans);
    }
    return 0;
}
