#include <stdio.h>
#define CASE(a) printf("Case %d:\n", a)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define For(i, n) for (i = 0; i < n; i++)
#define pfn(n) printf("%d\n", n)
#define mem(a, b) memset(a, b, sizeof(a))
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
char v[505][505];
int m, n, vis[505][505], cry[100005], ans;
int valid(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && v[x][y] != '#')
        return 1;
    return 0;
}
void dfs(int i, int j, int m)
{
    vis[i][j] = m;
    if (v[i][j] == 'C')
        ans++;
    int k;
    For(k, 4)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x, y) && vis[x][y] == -1)
            dfs(x, y, m);
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int t, cs = 1, q, x, y, i, j;
    sf(t);
    while (t--)
    {
        mem(vis, -1);
        mem(cry, 0);
        sfff(n, m, q);
        For(i, n)
            scanf("%s", v[i]);
        int num = 0;
        For(i, n)
            For(j, m) if (v[i][j] != '#' && vis[i][j] == -1)
        {
            ans = 0;
            dfs(i, j, num);
            cry[num] = ans;
            num++;
        }
        CASE(cs++);
        while (q--)
        {
            sff(x, y);
            pfn(cry[vis[x - 1][y - 1]]);
        }
    }
    return 0;
}
