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
/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)
/// http://www.lightoj.com/volume_showproblem.php?problem=1222
namespace mcmf
{
/// Number of edges * 2
const int MAX = 5010;
const long long INF = inf;
long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
int n, m, s, t, Q[MAX * 100], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];
void init(int nodes, int source, int sink)
{
    m = 0, n = nodes, s = source, t = sink;
    for (int i = 0; i <= n; i++)
        last[i] = -1;
}
/// c = capacity , w = cost
void addEdge(int u, int v, long long c, long long w)
{
    adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
    adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
}
bool spfa()
{
    int i, j, x, f = 0, l = 0;
    for (i = 0; i <= n; i++)
        visited[i] = 0, dis[i] = INF;
    dis[s] = 0, Q[l++] = s;
    while (f < l)
    {
        i = Q[f++];
        for (j = last[i]; j != -1; j = link[j])
        {
            if (flow[j] < cap[j])
            {
                x = adj[j];
                if (dis[x] > dis[i] + cost[j])
                {
                    dis[x] = dis[i] + cost[j], from[x] = j;
                    if (!visited[x])
                    {
                        visited[x] = 1;
                        if (f && rand() & 7)
                            Q[--f] = x;
                        else
                            Q[l++] = x;
                    }
                }
            }
        }
        visited[i] = 0;
    }
    return (dis[t] != INF);
}
pair<long long, long long> solve()
{
    int i, j;
    long long mincost = 0, maxflow = 0;
    while (spfa())
    {
        long long aug = INF;
        for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i])
        {
            aug = min(aug, cap[j] - flow[j]);
        }
        for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i])
        {
            flow[j] += aug, flow[j ^ 1] -= aug;
        }
        maxflow += aug, mincost += aug * dis[t];
    }
    return make_pair(mincost, maxflow);
}
} // namespace mcmf
int main()
{
    int t, n, m, p, u, v, c, w, cs = 1;
    sf(t);
    while (t--)
    {
        sfff(n, m, p);
        mcmf::init(n + 1, 0, n);
        mcmf::addEdge(0, 1, p, 0);
        while (m--)
        {
            sff(u, v);
            sff(w, c);
            mcmf::addEdge(u, v, w, c);
            mcmf::addEdge(v, u, w, c);
        }
        CASE(cs++);
        pair<i64, i64> ans = mcmf::solve();
        if (ans.ss == p)
            cout << ans.ff << endl;
        else
            puts("impossible");
        //      cout << ans.ff << " " << ans.ss << endl;
    }
}
