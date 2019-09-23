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
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
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
char s[30][30];
vpi g, h;
int dis[30][30][30][30];
int n;
vpi v[55];
bool vis[55];
int mg[55], mh[55];
int lim;
bool valid(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < n && s[x][y] == '.')
        return 1;
    return 0;
}
void bfs(int sx, int sy)
{
    queue<pii> q;
    dis[sx][sy][sx][sy] = 0;
    q.push(mp(sx, sy));
    while (!q.empty())
    {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        int dd = dis[sx][sy][x][y];
        For(i, 4)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (valid(xx, yy) && dis[sx][sy][xx][yy] == -1)
            {
                dis[sx][sy][xx][yy] = dd + 1;
                q.push(mp(xx, yy));
            }
        }
    }
}
void make_graph()
{
    mem(v, NULL);
    mem(dis, -1);
    For(i, g.sz)
    {
        bfs(g[i].ff, g[i].ss);
        For(j, h.sz) if (dis[g[i].ff][g[i].ss][h[j].ff][h[j].ss] != -1)
        {
            //                                cout << g[i].ff << " " << g[i].ss << " " << h[j].ff << " " << h[j].ss << endl;
            v[i].pb(mp(j, dis[g[i].ff][g[i].ss][h[j].ff][h[j].ss]));
        }
    }
}
bool findmatch(int x)
{
    vis[x] = 1;
    For(i, v[x].sz)
    {
        int y = v[x][i].ff;
        int dd = v[x][i].ss;
        if (dd > lim)
            continue;
        if (mh[y] == -1 || (!vis[mh[y]] && findmatch(mh[y])))
        {
            mg[x] = y;
            mh[y] = x;
            return 1;
        }
    }
    return 0;
}
int bpm()
{
    int ans = 0;
    mem(mg, -1);
    mem(mh, -1);
    For(i, g.sz)
    {
        mem(vis, 0);
        if (mg[i] != -1 || findmatch(i))
            ans++;
    }
    return ans;
}
int f()
{
    Fre(i, 1, 50)
    {
        lim = i;
        int res = bpm();
        if (res == (int)h.sz)
            return 2 * i + 2;
    }
    return -1;
}
int main()
{
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        g.clr;
        h.clr;
        sf(n);
        For(i, n)
        {
            scanf("%s", s[i]);
            For(j, n) if (s[i][j] == 'G')
            {
                s[i][j] = '.';
                g.pb(mp(i, j));
            }
            else if (s[i][j] == 'H')
            {
                s[i][j] = '.';
                h.pb(mp(i, j));
            }
        }
        make_graph();
        CASE(cs++);
        int res = f();
        if (res != -1)
            pfn(f());
        else
            puts("Vuter Dol Kupokat");
    }
    return 0;
}
