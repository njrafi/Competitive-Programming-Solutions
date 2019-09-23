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
bool checkbit(int mask, int bit) { return mask & (1 << bit); }
int setbit(int mask, int bit) { return mask | (1 << bit); }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 505
vpi v[mxn];
int dis[mxn][mxn];
int shop[mxn];
void dij(int sou)
{
    For(i, mxn)
        dis[sou][i] = inf;
    priority_queue<pii, vector<pii>, greater<pii>> p;
    dis[sou][sou] = 0;
    p.push(mp(0, sou));
    while (!p.empty())
    {
        int u = p.top().ss;
        p.pop();
        For(i, v[u].sz)
        {
            int vv = v[u][i].ff;
            int vw = v[u][i].ss;
            if (dis[sou][vv] > dis[sou][u] + vw)
            {
                dis[sou][vv] = dis[sou][u] + vw;
                p.push(mp(dis[sou][vv], vv));
            }
        }
    }
}
pii dp[18][1 << 16];
int vis[18][1 << 16];
int n;
int s;
int cs = 1;
pii f(int id, int mask)
{
    if (vis[id][mask] == cs)
        return dp[id][mask];
    vis[id][mask] = cs;
    int u = shop[id];
    /// goint to the end
    pii ans = mp(-inf, inf);
    if (dis[u][n - 1] != inf)
        ans = mp(0, -dis[u][n - 1]);
    For(i, s) if (!checkbit(mask, i))
    {
        int vv = shop[i];
        int vw = dis[u][vv];
        if (vw == inf)
            continue;
        pii tem = f(i, setbit(mask, i));
        tem.ff += 1;
        tem.ss -= vw;
        ans = max(ans, tem);
    }
    return dp[id][mask] = ans;
}
int main()
{
    int t, m, a, b, c;
    fastRead(&t);
    while (t--)
    {
        mem(v, NULL);
        fastRead(&n);
        fastRead(&m);
        fastRead(&s);
        For(i, s)
            fastRead(&shop[i]);
        while (m--)
        {
            fastRead(&a);
            fastRead(&b);
            fastRead(&c);
            v[a].pb(mp(b, c));
        }
        dij(0);
        For(i, s)
            dij(shop[i]);
        shop[s] = 0;
        CASE(cs++);
        pii ans = f(s, 0);
        if (ans.ff < 0)
            puts("Impossible");
        else
        {
            pfs(ans.ff);
            pfn(-ans.ss);
        }
    }
    return 0;
}
