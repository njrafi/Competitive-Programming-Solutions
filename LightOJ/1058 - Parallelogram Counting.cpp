#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
    bool operator<(const point &b) const
    {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
} node[1003], mid[1000003];
int func(int n)
{
    int m = 0, res = 0, cnt = 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            mid[m].x = node[i].x + node[j].x;
            mid[m].y = node[i].y + node[j].y;
            m++;
        }
    sort(mid, mid + m);
    for (int i = 0; i < m - 1; i++)
        if (mid[i].x == mid[i + 1].x && mid[i].y == mid[i + 1].y)
            cnt++;
        else
        {
            res += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    return res;
}
int main()
{
    int t, n, res;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> node[j].x >> node[j].y;
        res = func(n);
        printf("Case %d: %d\n", i, res);
    }
    return 0;
}
