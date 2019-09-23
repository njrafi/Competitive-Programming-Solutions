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
#define CASE(a) printf("Case %d:\n", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
inline void fastRead(int *a)
{
    register char c = 0;
    while (c < 33)
        c = gc();
    *a = 0;
    while (c > 33)
    {
        *a = *a * 10 + c - '0';
        c = gc();
    }
}
inline void fastWrite(int a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc(' ');
}
inline void fastWrite2(int a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc('\n');
}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 100005
/// disconnected nodes
bool disconnected[mxn];
int tot_disconnected;
namespace dom
{
bool taken[mxn];
/// tot node , root
int n, root;
/// main graph ulta edge
vi v[mxn];
/// after topology sort
vi topo;
/// p[x][y] means 2^y th parent of x
int p[mxn][22];
/// The dominator tree
vi tree[mxn];
/// Level of the node in tree
int l[mxn];
/// subtree size
int subSize[mxn];
int get_size(int u)
{
    subSize[u] = 1;
    For(i, tree[u].sz)
        subSize[u] += get_size(tree[u][i]);
    return subSize[u];
}
/// dfs for topSort
void dfs(int u)
{
    if (!taken[u])
    {
        For(i, v[u].sz)
            dfs(v[u][i]);
        topo.pb(u);
        taken[u] = 1;
    }
}
/// Update lca for u
void update_lca(int u)
{
    //        cout << "update lca called for " << u << endl;
    for (int j = 1;; j++)
    {
        if (p[u][j - 1] == -1)
            break;
        //                cout << "updating sparse : ";
        //                cout << u << " " << j << " " << p[p[u][j-1]][j-1] << endl;
        //                cout << j << " " << j << endl;
        p[u][j] = p[p[u][j - 1]][j - 1];
    }
}
int get_lca(int uu, int vv)
{
    if (l[uu] < l[vv])
        swap(uu, vv);
    int hi = log2(l[uu]) + 2;
    // bring both node to same level
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
void init()
{
    mem(taken, 0);
    mem(p, -1);
    mem(tree, NULL);
    topo.clr;
    mem(subSize, 0);
    /// top sort
    For(i, n)
        dfs(i);
    //        printf("The topology sorted order\n");
    //        For(i,topo.sz)
    //                cout << topo[i] << " ";
    //        cout << endl;
    /// remember to change for diff problems
    root = 0;
    l[root] = 0;
    /// Processing nodes
    //        printf("The Dominator tree: \n");
    For(i, topo.sz)
    {
        int u = topo[i];
        if (u == root || disconnected[u])
            continue;
        int par;
        if (v[u].sz == 1)
            par = v[u][0];
        else
        {
            par = get_lca(v[u][0], v[u][1]);
            Fre(j, 2, v[u].sz)
                par = get_lca(par, v[u][j]);
        }
        //                cout << par << " " << u << endl;
        tree[par].pb(u);
        l[u] = l[par] + 1;
        //                cout << "updating sparse : ";
        //                cout << u << " " << 0 << " " << par << endl;
        p[u][0] = par;
        update_lca(u);
    }
    get_size(root);
    //        printf("printing subtree size\n");
    //
    //        For(i,n)
    //                cout << i << " " << subSize[i] << endl;
}
void query()
{
    int k, inp;
    fastRead(&k);
    vi gg;
    while (k--)
    {
        fastRead(&inp);
        if (!disconnected[inp])
            gg.pb(inp);
    }
    if (gg.empty())
        fastWrite2(0);
    else
    {
        int par;
        if (gg.sz == 1)
            par = gg[0];
        else
        {
            par = get_lca(gg[0], gg[1]);
            Fre(i, 2, gg.sz)
                par = get_lca(par, gg[i]);
        }
        //                cout << "inside query : " ;
        //                cout << gg.sz << " " << par << endl;
        fastWrite(l[par] + 1);
        fastWrite2(subSize[par]);
    }
}
} // namespace dom
namespace dijstra
{
int dis[mxn];
vpi v[mxn];
int n;
void init(int nn)
{
    n = nn;
    mem(v, NULL);
    For(i, mxn)
        dis[i] = inf;
    mem(disconnected, 0);
    tot_disconnected = 0;
}
void dij()
{
    dis[0] = 0;
    priority_queue<pii, vpi, greater<pii>> p;
    p.push({0, 0});
    while (!p.empty())
    {
        int u = p.top().ss;
        int udis = p.top().ff;
        p.pop();
        if (dis[u] < udis)
            continue;
        For(i, v[u].sz)
        {
            int vv = v[u][i].ff;
            int ww = v[u][i].ss;
            if (dis[vv] > dis[u] + ww)
            {
                dis[vv] = dis[u] + ww;
                p.push({dis[vv], vv});
            }
        }
    }
    //        printf("Printing initial graph min distance\n");
    For(i, n)
    {
        if (dis[i] == inf)
        {
            disconnected[i] = 1;
            tot_disconnected++;
        }
        //                cout << i << " " << dis[i] << endl;
    }
}
void make_graph()
{
    mem(dom::v, NULL);
    For(u, n)
        For(i, v[u].sz)
    {
        int vv = v[u][i].ff;
        int ww = v[u][i].ss;
        if (dis[vv] == dis[u] + ww)
        {
            //                                printf("Adding edge: %d to %d\n", u,vv);
            dom::v[vv].pb(u);
        }
    }
    dom::n = n;
}
} // namespace dijstra
int main()
{
    int t, cs = 1;
    int n, m, a, b, c, q;
    fastRead(&t);
    while (t--)
    {
        fastRead(&n);
        fastRead(&m);
        dijstra::init(n);
        while (m--)
        {
            fastRead(&a);
            fastRead(&b);
            fastRead(&c);
            dijstra::v[a].pb({b, c});
            dijstra::v[b].pb({a, c});
        }
        dijstra::dij();
        dijstra::make_graph();
        dom::init();
        fastRead(&q);
        CASE(cs++);
        while (q--)
            dom::query();
    }
    return 0;
}
