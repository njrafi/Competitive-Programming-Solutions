#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, res, diff, pos, lift;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> pos >> lift;
        if (lift >= pos)
            diff = lift;
        else
            diff = 2 * pos - lift;
        res = diff * 4 + 19;
        printf("Case %d: %d\n", i, res);
    }
    return 0;
}
