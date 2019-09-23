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
#define mxn 505
struct info
{
    /// starting time,source, destination
    int st, sx, sy, dx, dy;
    info() {}
    info(int _st, int _sx, int _sy, int _dx, int _dy)
    {
        st = _st;
        sx = _sx;
        sy = _sy;
        dx = _dx;
        dy = _dy;
    }
};
vector<info> node;
int matchL[mxn], matchR[mxn];
bool vis[mxn];
int parent[mxn];
int dis[mxn];
vi v[mxn];
int findmatch(int u)
{
    vis[u] = 1;
    For(i, v[u].sz)
    {
        int vv = v[u][i];
        int k = matchR[vv];
        if (!matchR[vv] || parent[matchR[vv]] == u)
        {
            if (!matchR[vv] || findmatch(k))
            {
                matchL[u] = vv;
                matchR[vv] = u;
                return 1;
            }
        }
    }
    return 0;
}
bool bfs()
{
    mem(vis, 0);
    queue<int> q;
    Fre(i, 1, node.sz) if (!matchL[i])
    {
        vis[i] = 1;
        q.push(i);
        dis[i] = 0;
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        For(i, v[u].sz)
        {
            int vv = v[u][i];
            int d = matchR[vv];
            if (!d)
                return 1;
            else if (!vis[d])
            {
                q.push(d);
                parent[d] = u;
                vis[d] = 1;
                dis[d] = dis[u] + 1;
            }
        }
    }
    return 0;
}
int bpm()
{
    int ans = 0;
    while (bfs())
    {
        Fre(i, 1, node.sz) if (!matchL[i] && findmatch(i))
            ans++;
    }
    mem(matchL, 0);
    mem(matchR, 0);
    node.clr;
    mem(v, NULL);
    return ans;
}
int main()
{
    int t, sx, sy, dx, dy, h, m, cs = 1, n;
    sf(t);
    while (t--)
    {
        node.pb(info());
        sf(n);
        For(i, n)
        {
            scanf("%d:%d", &h, &m);
            sff(sx, sy);
            sff(dx, dy);
            node.pb(info(h * 60 + m, sx, sy, dx, dy));
        }
        Fre(i, 1, node.sz)
            Fre(j, 1, node.sz)
        {
            /// if there is a path from i to j
            /// make an edge from i to j
            int dis = abs(node[i].dx - node[j].sx);
            dis += abs(node[i].dy - node[j].sy);
            dis += abs(node[i].sx - node[i].dx);
            dis += abs(node[i].sy - node[i].dy);
            if (node[i].st + dis < node[j].st)
                v[i].pb(j);
        }
        CASE(cs++);
        pfn(n - bpm());
    }
    return 0;
}
