#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main()
{
    int t, n;
    double R, r;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> R >> n;
        r = (R * sin(pi / n)) / (1 + sin(pi / n));
        printf("Case %d: %.10f\n", i, r);
    }
    return 0;
}
