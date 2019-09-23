#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, k;
int dp[10010][103];
vector<pii> v;
bool cmp(pii a, pii b)
{
    return (a.second > b.second);
}
int main()
{
    int i, j, a, b, total, t, p, sum;
    total = sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        total += a;
        v.push_back(make_pair(a, 0));
    }
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &b);
        v[i].second = b;
        sum += b;
    }
    sort(v.begin(), v.end(), cmp);
    b = 0;
    for (i = 0; i < v.size(); ++i)
    {
        b += v[i].second;
        k++;
        if (b >= total)
            break;
    }
    if (k == n)
    {
        t = 0;
    }
    else
    {
        memset(dp, -1, sizeof(dp));
        for (i = 0; i <= k; ++i)
            dp[0][i] = 0;
        for (i = 0; i < n; ++i)
        {
            for (j = sum; j >= 0; --j)
            {
                for (p = k; p >= 0; --p)
                {
                    if (j - v[i].second >= 0 && p - 1 >= 0 && dp[j - v[i].second][p - 1] != -1)
                        dp[j][p] = max(dp[j][p], v[i].first + dp[j - v[i].second][p - 1]);
                }
            }
            /*  t=0;
            for(j=v[i].second; j<=sum; ++j){
                t=max(t,dp[j][k]);
                printf("%d ",t);
            }
            puts("");*/
        }
        t = 0;
        for (i = total; i <= sum; ++i)
        {
            t = max(t, dp[i][k]);
            // printf("%d\n",t);
        }
        t = total - t;
    }
    printf("%d %d\n", k, t);
    return 0;
}