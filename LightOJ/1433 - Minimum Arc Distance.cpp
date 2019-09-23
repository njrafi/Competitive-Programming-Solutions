#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double ox, oy, ax, ay, bx, by, ob, ab;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        ob = sqrt((bx - ox) * (bx - ox) + (by - oy) * (by - oy));
        ab = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
        printf("Case %d: %.8f\n", i, ob * 2 * asin(ab / (2 * ob)));
    }
    return 0;
}
