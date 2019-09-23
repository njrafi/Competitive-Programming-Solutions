#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y, k, n, x, x_max;
    cin >> y >> k >> n;
    x_max = n - y;
    x = k - y % k;
    if (x > x_max)
    {
        cout << -1;
        return 0;
    }
    while (x <= x_max)
    {
        cout << x << ' ';
        x += k;
    }
    return 0;
}