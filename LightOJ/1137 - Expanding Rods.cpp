#include <bits/stdc++.h>
#define accuracy 1e-8
using namespace std;
int main()
{
    int t;
    double l, s, n, c, low, high, h, r;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> l >> n >> c;
        s = (1 + n * c) * l;
        low = 0;
        high = l / 2;
        while (high - low > accuracy)
        {
            h = (high + low) / 2;
            r = (4 * h * h + l * l) / (8 * h);
            if (2 * r * asin(l / (2 * r)) < s)
                low = h;
            else
                high = h;
        }
        printf("Case %d: %.9f\n", i, h);
    }
    return 0;
}
