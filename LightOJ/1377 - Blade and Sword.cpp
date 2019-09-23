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
vs v;
vpi tele;
int dis[2][202][202];
bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= v.sz || y >= v[0].sz || v[x][y] == '#')
        return 0;
    return 1;
}
void bfs(int idx, int st, int en)
{
    For(i, v.sz)
        For(j, v[0].sz)
            dis[idx][i][j] = inf;
    queue<pii> q;
    dis[idx][st][en] = 0;
    q.push(mp(st, en));
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        if (v[u.ff][u.ss] == '*' && tele.sz == 1)
            continue;
        For(i, 4)
        {
            int xx = u.ff + dx[i];
            int yy = u.ss + dy[i];
            int cost = 1;
            if (v[u.ff][u.ss] == '*')
                cost = 3;
            if (valid(xx, yy) && dis[idx][xx][yy] > dis[idx][u.ff][u.ss] + cost)
            {
                dis[idx][xx][yy] = dis[idx][u.ff][u.ss] + cost;
                q.push(mp(xx, yy));
            }
        }
    }
    //        For(i,v.sz)
    //        {
    //                For(j,v[i].sz)
    //                        cout << dis[idx][i][j] << "  ";
    //                cout << endl;
    //        }
}
int main()
{
    int t, cs = 1, n, m;
    int sx, sy, dx, dy;
    string s;
    char ss[205];
    sf(t);
    while (t--)
    {
        v.clr;
        tele.clr;
        sff(n, m);
        For(i, n)
        {
            scanf("%s", ss);
            s = ss;
            For(j, s.sz)
            {
                if (s[j] == 'P')
                    sx = i, sy = j;
                else if (s[j] == 'D')
                    dx = i, dy = j;
                else if (s[j] == '*')
                    tele.pb(mp(i, j));
            }
            v.pb(s);
        }
        int ans = inf;
        bfs(0, sx, sy);
        ans = min(ans, dis[0][dx][dy]);
        bfs(1, dx, dy);
        vpi sdis, ddis;
        For(i, tele.sz)
        {
            sdis.pb(mp(dis[0][tele[i].ff][tele[i].ss], i));
            ddis.pb(mp(dis[1][tele[i].ff][tele[i].ss], i));
        }
        sort(all(sdis));
        sort(all(ddis));
        For(i, min(3, (int)sdis.sz))
            For(j, min(3, (int)ddis.sz)) if (sdis[i].ss != ddis[j].ss)
                ans = min(ans, sdis[i].ff + ddis[j].ff + 1);
        CASE(cs++);
        if (ans == inf)
            puts("impossible");
        else
            pfn(ans);
    }
    /*
1
1 5
P.*.D
*/
    return 0;
}
