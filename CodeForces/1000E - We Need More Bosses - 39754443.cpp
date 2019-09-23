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
#define vll vector<i64>
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
#define inf INT_MAX / 2
#define mod 1000000007
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
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d:\n", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
//matrix rot(matrix a){matrix res;res.row = a.col;res.col = a.row;For(i,a.row)For(j,a.col)res.mat[j][a.row-i-1] = a.mat[i][j];return res;}
#define mxn 300005
vi v[mxn];
/// for finding bridge
int timen, parent[mxn], root, d[mxn], low[mxn];
bool vis[mxn];
map<pii, bool> isb; /// is bridge
                    /// getting the bridge
void dfs(int s)
{
    vis[s] = 1;
    timen++;
    low[s] = d[s] = timen;
    For(i, v[s].sz)
    {
        int w = v[s][i];
        if (parent[s] == w)
            continue;
        if (vis[w])
            low[s] = min(low[s], d[w]);
        else
        {
            parent[w] = s;
            dfs(w);
            low[s] = min(low[s], low[w]);
            if (d[s] < low[w])
            {
                isb[mp(s, w)] = 1;
                isb[mp(w, s)] = 1;
            }
        }
    }
}
void ini()
{
    timen = 0;
    mem(parent, -1);
    mem(v, NULL);
}
vi w[mxn]; /// new tree
int fcomp; /// free component
void dfs2(int n, int comp)
{
    vis[n] = 1;
    For(i, v[n].sz)
    {
        int vv = v[n][i];
        if (vis[vv])
            continue;
        if (isb.find(mp(n, vv)) == isb.end())
            dfs2(vv, comp);
        else
        {
            w[comp].pb(fcomp);
            w[fcomp].pb(comp);
            fcomp++;
            dfs2(vv, fcomp - 1);
        }
    }
}
int dis[mxn];
int bfs(int start, int n)
{
    For(i, mxn)
        dis[i] = inf;
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        For(i, w[u].sz)
        {
            int vv = w[u][i];
            if (dis[vv] > dis[u] + 1)
            {
                dis[vv] = dis[u] + 1;
                q.push(vv);
            }
        }
    }
    int mx = INT_MIN, ans;
    Fre(i, 1, n) if (dis[i] > mx)
    {
        mx = dis[i];
        ans = i;
    }
    return ans;
}
int main()
{
    int a, b, n, m, cs = 1;
    ini();
    sff(n, m);
    while (m--)
    {
        sff(a, b);
        v[a].pb(b);
        v[b].pb(a);
    }
    Fre(i, 1, n + 1)
    {
        if (!vis[i])
        {
            root = i;
            dfs(root);
        }
    }
    mem(vis, 0);
    fcomp = 2;
    dfs2(1, 1);
    cout << dis[bfs(bfs(1, fcomp), fcomp)] << endl;
    return 0;
}
