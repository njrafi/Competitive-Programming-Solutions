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
#define mxn 10004
vpi v[mxn]; /// Main Graph
            /// for finding bridge
int timen, parent[mxn], root, d[mxn], low[mxn];
bool vis[mxn];
int in[mxn];
/// Is Bridge?
bool isb[mxn * 3];
/// getting the bridges
void dfs(int s)
{
    vis[s] = 1;
    timen++;
    low[s] = d[s] = timen;
    For(i, v[s].sz)
    {
        int w = v[s][i].ff;
        int id = v[s][i].ss;
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
                isb[id] = 1;
        }
    }
}
void ini(int n, int m)
{
    timen = 0;
    For(i, n + 2)
    {
        parent[i] = -1;
        v[i].clr;
        vis[i] = 0;
        in[i] = 0;
    }
    For(i, m + 2)
        isb[i] = 0;
}
int fcomp; /// free component
/// This dfs will make a tree using only the bridges as its edge
/// if 2 nodes are connected without a bridge, they will be considered as same node
void dfs2(int n, int comp)
{
    vis[n] = 1;
    For(i, v[n].sz)
    {
        int vv = v[n][i].ff;
        int id = v[n][i].ss;
        if (vis[vv])
            continue;
        if (!isb[id])
            dfs2(vv, comp);
        else
        {
            in[comp]++;
            in[fcomp]++;
            //                        cout << comp << " " << fcomp << endl;
            fcomp++;
            dfs2(vv, fcomp - 1);
        }
    }
}
int dis[mxn];
int main()
{
    int a, b, n, m, cs = 1, t;
    fastRead(&t);
    while (t--)
    {
        fastRead(&n);
        fastRead(&m);
        ini(n, m);
        For(i, m)
        {
            fastRead(&a);
            fastRead(&b);
            v[a].pb({b, i});
            v[b].pb({a, i});
        }
        dfs(0);
        For(i, n)
            vis[i] = 0;
        fcomp = 2;
        dfs2(0, 1);
        int leaf = 0;
        Fre(i, 1, fcomp) if (in[i] == 1)
            leaf++;
        int ans = leaf / 2;
        if (leaf % 2)
            ans++;
        CASE(cs++);
        fastWrite(ans);
    }
    return 0;
}
