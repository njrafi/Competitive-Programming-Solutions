#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x1[105], x2[105], y1[105], y2[105], z1[105], z2[105], n, X, Y, Z;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> x1[j] >> y1[j] >> z1[j] >> x2[j] >> y2[j] >> z2[j];
        sort(x1, x1 + n);
        sort(x2, x2 + n);
        sort(y1, y1 + n);
        sort(y2, y2 + n);
        sort(z1, z1 + n);
        sort(z2, z2 + n);
        X = x2[0] - x1[n - 1];
        Y = y2[0] - y1[n - 1];
        Z = z2[0] - z1[n - 1];
        if (X * Y * Z < 0)
            X = 0;
        printf("Case %d: %lld\n", i, X * Y * Z);
    }
    return 0;
}
