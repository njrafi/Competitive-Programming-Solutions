#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define LIM 100005
using namespace std;
int n, m;
vi g[LIM];
int dp[LIM];
int f(int u)
{
    if (dp[u] != -1)
        return dp[u];
    int ans = 0;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (g[v].size() > g[u].size())
        {
            ans = max(ans, 1 + f(v));
        }
    }
    return dp[u] = ans;
}
int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, 1 + f(i));
    }
    printf("%d\n", ans);
}