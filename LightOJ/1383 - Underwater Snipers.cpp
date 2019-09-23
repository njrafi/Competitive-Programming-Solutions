#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long LL;
const double pi = acos(-1.0);
const double eqs = 1e-10;
struct point
{
    LL x, y;
} a[10001], f[10001];
LL k, n, s, d;
bool cmp(struct point w, struct point v)
{
    return w.y < v.y;
}
bool gao(int mid)
{
    for (int i = 0; i < n; i++)
    {
        if (mid + a[i].y > d)
            return false;
        LL t = (LL)sqrt(d * d * 1.0 - (mid + a[i].y) * (mid + a[i].y) * 1.0);
        f[i].x = a[i].x - t, f[i].y = a[i].x + t;
    }
    sort(f, f + n, cmp);
    LL ans = 0;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        ans++;
        if (ans > s)
            return false;
        while (f[i].y >= f[k].x)
        {
            k++;
            if (k >= n)
                break;
        }
        i = k - 1;
    }
    if (ans > s)
        return false;
    return true;
}
int main()
{
    int T, cnt = 0;
    scanf("%d", &T);
    while (T--)
    {
        LL ans = 0;
        int flag = 0;
        scanf("%lld%lld%lld%lld", &k, &n, &s, &d);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &a[i].x, &a[i].y);
            a[i].y -= k;
        }
        LL l = 0, r = d;
        while (l <= r)
        {
            LL mid = (l + r) >> 1;
            if (gao(mid))
            {
                flag = 1;
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        printf("Case %d: ", ++cnt);
        if (!flag)
            printf("impossible\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}