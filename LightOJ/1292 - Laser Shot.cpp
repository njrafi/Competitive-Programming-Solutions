#include <bits/stdc++.h>
using namespace std;
int func(int n, int x[], int y[])
{
    int ans = -1;
    if (n == 1)
        return 1;
    for (int i = 0; i < n; i++)
    {
        map<double, int> slope;
        map<double, int>::iterator k;
        for (int j = i + 1; j < n; j++)
            slope[((double)(x[i] - x[j]) / (double)(y[i] - y[j]))]++;
        int tem = -1;
        for (k = slope.begin(); k != slope.end(); k++)
            if (k->second > tem)
                tem = k->second;
        if (tem > ans)
            ans = tem;
    }
    return ans + 1;
}
int main()
{
    int t, n, x[705], y[706], res;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        res = func(n, x, y);
        if (n == 1)
            res = 1;
        printf("Case %d: %d\n", j, res);
    }
    return 0;
}
