#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
using namespace std;
#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int, int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int, vector<int>, greater<int>>
#define mpi map<int, int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX / 2
#define infll LLONG_MAX / 3
#define For(i, n) for (int i = 0; i < n; i++)
#define Fre(i, a, b) for (int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 100035
struct edge
{
    int u, v, cost;
    bool operator<(edge const &gg) const
    {
        return cost < gg.cost;
    }
};
vector<edge> e;
/// for the tree
vpi v[mxn];
vpi mainGraph[mxn];
int uf[mxn];
i64 treeDis[mxn];
i64 graphDis[23][mxn];
int badidx;
void ini(int n)
{
    For(j, 23)
        For(i, n + 1)
    {
        uf[i] = i;
        treeDis[i] = infll;
        graphDis[j][i] = infll;
    }
}
int root(int u)
{
    if (u == uf[u])
        return u;
    return uf[u] = root(uf[u]);
}
void uni(int x, int y)
{
    uf[root(x)] = root(y);
}
#define pll pair<i64, int>
void dij(int idx, int u)
{
    graphDis[idx][u] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> p;
    p.push({0, u});
    while (!p.empty())
    {
        int u = p.top().ss;
        i64 uCost = p.top().ff;
        p.pop();
        if (graphDis[idx][u] < uCost)
            continue;
        For(i, mainGraph[u].sz)
        {
            int vv = mainGraph[u][i].ff;
            int newCost = mainGraph[u][i].ss;
            if (uCost + newCost < graphDis[idx][vv])
            {
                graphDis[idx][vv] = uCost + newCost;
                p.push({graphDis[idx][vv], vv});
            }
        }
    }
}
void kruskal()
{
    sort(all(e));
    For(i, e.sz) if (root(e[i].u) != root(e[i].v)) //finding cycle
    {
        uni(e[i].u, e[i].v);
        /// making tree
        v[e[i].u].pb({e[i].v, e[i].cost});
        v[e[i].v].pb({e[i].u, e[i].cost});
    }
    else dij(badidx++, e[i].u);
}
int p[mxn][22];
int l[mxn]; // level
void dfs(int s, int par, int lev, i64 cost)
{
    p[s][0] = par;
    l[s] = lev;
    treeDis[s] = cost;
    For(i, v[s].sz) if (l[v[s][i].ff] == -1)
        dfs(v[s][i].ff, s, lev + 1, cost + v[s][i].ss);
}
void gen_table(int n)
{
    mem(p, -1);
    mem(l, -1);
    dfs(1, -1, 0, 0);
    // (1<<j) = po(2,j)
    for (int j = 1; (1 << j) < n; j++)
        Fre(i, 1, n + 1) if (p[i][j - 1] != -1)
            p[i][j] = p[p[i][j - 1]][j - 1];
}
int lca(int uu, int vv)
{
    if (l[uu] < l[vv])
        swap(uu, vv);
    int hi = log2(l[uu]) + 2;
    for (int i = hi; i >= 0; i--)
        if (l[uu] - (1 << i) >= l[vv])
            uu = p[uu][i];
    if (uu == vv)
        return uu;
    for (int i = hi; i >= 0; i--)
        if (p[uu][i] != -1 && p[uu][i] != p[vv][i])
        {
            uu = p[uu][i];
            vv = p[vv][i];
        }
    return p[uu][0];
}
int main()
{
    int n, m, a, b, c, q;
    sff(n, m);
    ini(n);
    while (m--)
    {
        sfff(a, b, c);
        e.pb({a, b, c});
        mainGraph[a].pb({b, c});
        mainGraph[b].pb({a, c});
    }
    kruskal();
    gen_table(n);
    sf(q);
    while (q--)
    {
        sff(a, b);
        i64 mn = treeDis[a] + treeDis[b] - 2 * treeDis[lca(a, b)];
        For(i, badidx)
            mn = min(mn, graphDis[i][a] + graphDis[i][b]);
        cout << mn << endl;
    }
    return 0;
}
