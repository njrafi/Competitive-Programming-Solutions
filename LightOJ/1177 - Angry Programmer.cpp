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
/// Dinic's algorithm for directed graphs (0 based index for graphs)
/// Complexity( E * V^2)
/// For undirected graphs, just add two directed edges
/// implemented from zahin vai library,check it if node Flow is needed
#define mxn 30004 // vertex number
namespace flow
{
struct edge
{
    int u, v;
    long long cap, flow;
    edge() {}
    edge(int a, int b, long long c, long long f)
    {
        u = a, v = b, cap = c, flow = f;
    }
};
vi adj[mxn];
vector<edge> e;
int s, t, ptr[mxn], dis[mxn];
/// initialize things
void init(int source, int sink)
{
    e.clr;
    mem(adj, NULL);
    s = source;
    t = sink;
}
/// adds a directed edge from a to b with capacity c
void addEdge(int a, int b, long long c)
{
    adj[a].pb(e.sz);
    e.pb(edge(a, b, c, 0));
    adj[b].pb(e.sz);
    e.pb(edge(b, a, 0, 0));
}
/// just a bfs from source to sink
/// return 1 if sink is reachable
bool bfs()
{
    mem(dis, -1);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty() && dis[t] == -1)
    {
        int u = q.front();
        q.pop();
        For(i, adj[u].sz)
        {
            int id = adj[u][i];
            int v = e[id].v;
            if (dis[v] == -1 && e[id].flow < e[id].cap)
            {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    return (dis[t] != -1);
}
long long dfs(int u, long long f)
{
    if (u == t || !f)
        return f;
    while (ptr[u] < adj[u].sz)
    {
        int id = adj[u][ptr[u]];
        int v = e[id].v;
        if (dis[v] == dis[u] + 1)
        {
            long long x = dfs(v, min(f, e[id].cap - e[id].flow));
            if (x)
            {
                e[id].flow += x;
                e[id ^ 1].flow -= x;
                return x;
            }
        }
        ptr[u]++;
    }
    return 0;
}
long long dinic()
{
    long long res = 0;
    while (bfs())
    {
        mem(ptr, 0);
        while (long long f = dfs(s, infll))
            res += f;
    }
    return res;
}
} // namespace flow
namespace nodeFlow
{
void init(int n, int s, int t, vector<i64> capacity)
{
    flow::init(s * 2, t * 2 + 1);
    for (int i = 1; i <= n; i++)
    {
        flow::addEdge(i * 2, i * 2 + 1, capacity[i]);
        flow::addEdge(i * 2 + 1, i * 2, capacity[i]);
    }
    /// converting the node to edge
}
void addEdge(int a, int b, long long c)
{
    flow::addEdge(a * 2 + 1, b * 2, c);
}
long long dinic()
{
    return flow::dinic();
}
} // namespace nodeFlow
int main()
{
    int tt, n, inp, a, b, c, cs = 1, q;
    sf(tt);
    while (tt--)
    {
        vector<long long> v;
        v.pb(0);
        v.pb(infll);
        sff(n, q);
        For(i, n - 2)
        {
            sf(inp);
            v.pb(inp);
        }
        v.pb(infll);
        nodeFlow::init(n, 1, n, v);
        while (q--)
        {
            sfff(a, b, c);
            nodeFlow::addEdge(a, b, c);
            nodeFlow::addEdge(b, a, c);
        }
        CASE(cs++);
        cout << nodeFlow::dinic() << endl;
    }
    return 0;
}
