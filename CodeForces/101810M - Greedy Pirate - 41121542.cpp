#include <bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define LIM 100005
using namespace std;
int n, sum;
vi g[LIM], c[LIM];
vi gg[LIM], cc[LIM];
vi niche[LIM], nichec[LIM], upore[LIM], uporec[LIM];
int vis[LIM], lev[LIM];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i], w = c[u][i];
        if (vis[v])
            continue;
        niche[u].pb(v);
        nichec[u].pb(w);
        dfs(v);
    }
}
void dfsx(int u)
{
    vis[u] = 1;
    for (int i = 0; i < gg[u].size(); i++)
    {
        int v = gg[u][i], w = cc[u][i];
        if (vis[v])
            continue;
        upore[u].pb(v);
        uporec[u].pb(w);
        dfsx(v);
    }
}
int par[LIM][20], downCost[LIM][20], upCost[LIM][20];
void dfs2(int u, int lv = 0)
{
    vis[u] = 1;
    lev[u] = lv + 1;
    for (int i = 0; i < niche[u].size(); i++)
    {
        int v = niche[u][i], w = nichec[u][i];
        if (vis[v])
            continue;
        par[v][0] = u;
        downCost[v][0] = w;
        dfs2(v, lv + 1);
    }
}
void dfs2x(int u, int lv = 0)
{
    vis[u] = 1;
    lev[u] = lv + 1;
    for (int i = 0; i < upore[u].size(); i++)
    {
        int v = upore[u][i], w = uporec[u][i];
        if (vis[v])
            continue;
        par[v][0] = u;
        upCost[v][0] = w;
        dfs2x(v, lv + 1);
    }
}
int f(int u, int v)
{
    int up;
    int cost = 0;
    up = 16;
    while (up >= 0)
    {
        if (lev[u] - (1 << up) >= lev[v])
        {
            cost += downCost[u][up];
            u = par[u][up];
            //            cout << "BUG" << endl;
        }
        up--;
    }
    up = 16;
    while (up >= 0)
    {
        if (lev[v] - (1 << up) >= lev[u])
        {
            cost += upCost[v][up];
            v = par[v][up];
        }
        up--;
    }
    if (u == v)
        return cost;
    //    cout << "SDSD " << u << ' ' << v << endl;
    up = 16;
    while (up >= 0)
    {
        if (par[u][up] != par[v][up])
        {
            cost += downCost[u][up];
            cost += upCost[v][up];
            u = par[u][up];
            v = par[v][up];
        }
        up--;
    }
    cost += downCost[u][0];
    cost += upCost[v][0];
    return cost;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(g, NULL, sizeof g);
        memset(c, NULL, sizeof c);
        memset(gg, NULL, sizeof gg);
        memset(cc, NULL, sizeof cc);
        memset(niche, NULL, sizeof niche);
        memset(upore, NULL, sizeof upore);
        memset(nichec, NULL, sizeof nichec);
        memset(uporec, NULL, sizeof uporec);
        memset(par, 0, sizeof par);
        memset(downCost, 0, sizeof downCost);
        memset(upCost, 0, sizeof upCost);
        scanf("%d", &n);
        sum = 0;
        for (int i = 1; i < n; i++)
        {
            int u, v, w1, w2;
            scanf("%d %d %d %d", &u, &v, &w1, &w2);
            g[u].pb(v);
            c[u].pb(w1);
            g[v].pb(u);
            c[v].pb(w2);
            gg[u].pb(v);
            cc[u].pb(w2);
            gg[v].pb(u);
            cc[v].pb(w1);
            sum += w1 + w2;
        }
        memset(vis, 0, sizeof vis);
        dfs(1);
        memset(vis, 0, sizeof vis);
        dfsx(1);
        memset(vis, 0, sizeof vis);
        dfs2(1);
        memset(vis, 0, sizeof vis);
        dfs2x(1);
        //        cout << "BUG" << endl;
        for (int p = 1; p <= 16; p++)
        {
            for (int u = 1; u <= n; u++)
            {
                if (!par[u][p - 1])
                    continue;
                par[u][p] = par[par[u][p - 1]][p - 1];
                downCost[u][p] = downCost[u][p - 1] + downCost[par[u][p - 1]][p - 1];
                upCost[u][p] = upCost[u][p - 1] + upCost[par[u][p - 1]][p - 1];
            }
        }
        //        cout << "GRAPH" << endl;
        //        for(int u=1; u<=n; u++) {
        //            for(int i=0; i<niche[u].size(); i++) cout << u << ' ' << niche[u][i] << ' ' << nichec[u][i] << ' ' << uporec[u][i] << endl;
        //        }
        //
        //        cout << "SPARSE" << endl;
        //        for(int p=0; p<3; p++) {
        //            cout << "FOR " << p << " : " << endl;
        //            for(int u=1; u<=n; u++) cout << u << ' ' << downCost[u][p] << ' ' << upCost[u][p] << endl;
        //        }
        //        int sum = 0;
        //        for(int i=0; i<)
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            //            cout << f(u,v) << endl;
            printf("%d\n", sum - f(u, v));
        }
    }
}