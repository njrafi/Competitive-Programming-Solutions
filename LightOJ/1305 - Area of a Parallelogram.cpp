#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, x[5], y[5], res;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        res = 0;
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
        x[3] = x[2] - (x[1] - x[0]);
        y[3] = y[0] + (y[2] - y[1]);
        x[4] = x[0];
        y[4] = y[0];
        for (int j = 0; j < 4; j++)
        {
            res += x[j] * y[j + 1];
            // cout << x[j] << "x"<< y[j+1] << " = " <<x[j]*y[j+1] << endl;
            res -= y[j] * x[j + 1];
            // cout << y[j] << "x"<< x[j+1] << " = " << y[j]*x[j+1] << endl;
        }
        printf("Case %d: %d %d %d\n", i, x[3], y[3], abs(res / 2));
    }
    return 0;
}
