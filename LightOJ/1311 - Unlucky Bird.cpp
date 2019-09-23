#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double v1, v2, v3, a1, a2;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> v1 >> v2 >> v3 >> a1 >> a2;
        printf("Case %d: %.8f %.8f\n", i, (v1 * v1 * a2 + v2 * v2 * a1) / (2 * a1 * a2), max(v1 * v3 / a1, v2 * v3 / a2));
    }
    return 0;
}
