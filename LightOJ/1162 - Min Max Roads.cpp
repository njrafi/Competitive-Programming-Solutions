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
#define mxn 100005
vi v[mxn], w[mxn];
int p[mxn][22], root, n;
int l[mxn]; // level
int mn[mxn][22];
int mx[mxn][22];
// p[x][y] means 2^y th parent of x
// mn[x][y] means the min edge in the path of 2^y th parent
// tot[x][y] means the total cost in the path of 2^y th parent
// pathsize will give us the number of edges between u and v
void input()
{
    int a, b, c;
    mem(v, NULL);
    mem(w, NULL);
    root = 1;
    sf(n);
    For(i, n - 1)
    {
        sfff(a, b, c);
        v[a].pb(b);
        v[b].pb(a);
        w[a].pb(c);
        w[b].pb(c);
    }
}
void dfs(int s, int par, int lev, int pedge) // determing the level of the nodes
{
    p[s][0] = par;
    mn[s][0] = pedge;
    mx[s][0] = pedge;
    l[s] = lev;
    For(i, v[s].sz) if (l[v[s][i]] == -1)
        dfs(v[s][i], s, lev + 1, w[s][i]);
}
void gen_table()
{
    mem(p, -1);
    mem(l, -1);
    dfs(root, -1, 0, inf);
    //        mx[root][0] = 0;
    for (int j = 1; (1 << j) < n; j++) // (1<<j) = po(2,j)
        Fre(i, 1, n + 1) if (p[i][j - 1] != -1)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
            mn[i][j] = min(mn[p[i][j - 1]][j - 1], mn[i][j - 1]);
            mx[i][j] = max(mx[p[i][j - 1]][j - 1], mx[i][j - 1]);
        }
}
pii query(int uu, int vv) // gives us lca , min cost edge , total cost , pathsize
{
    if (l[uu] < l[vv])
        swap(uu, vv);
    int hi = log2(l[uu]) + 2;
    int mnn = inf;
    int mxx = 0;
    for (int i = hi; i >= 0; i--) // bring both node to same level
        if (l[uu] - (1 << i) >= l[vv])
        {
            mnn = min(mn[uu][i], mnn);
            mxx = max(mx[uu][i], mxx);
            uu = p[uu][i];
        }
    if (uu == vv)
        return mp(mnn, mxx);
    for (int i = hi; i >= 0; i--)
        if (p[uu][i] != -1 && p[uu][i] != p[vv][i])
        {
            mnn = min(mn[uu][i], mnn);
            mxx = max(mx[uu][i], mxx);
            uu = p[uu][i];
            mnn = min(mn[vv][i], mnn);
            mxx = max(mx[vv][i], mxx);
            vv = p[vv][i];
        }
    mnn = min(mnn, min(mn[uu][0], mn[vv][0]));
    mxx = max(mxx, max(mx[uu][0], mx[vv][0]));
    return mp(mnn, mxx);
}
int main()
{
    //        WRITE;
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        input();
        gen_table();
        int q, a, b;
        sf(q);
        CASE(cs++);
        For(i, q)
        {
            sff(a, b);
            pii ans = query(a, b);
            pfs(ans.ff);
            pfn(ans.ss);
        }
    }
    return 0;
}
