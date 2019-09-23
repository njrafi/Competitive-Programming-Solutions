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
#define inf 536870911
#define infll 12345678901234567
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
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){return mask  (1<<bit);}
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
vs v;
vector<pair<pii, int>> sou;
string s;
int disx, disy;
int lev[102][102], n, m;
bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    return 1;
}
int bfs(int x, int y)
{
    mem(lev, -1);
    lev[x][y] = 0;
    queue<pii> q;
    q.push(mp(x, y));
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        For(i, 8)
        {
            int xx = u.ff + dx[i];
            int yy = u.ss + dy[i];
            if (valid(xx, yy) && lev[xx][yy] == -1)
            {
                lev[xx][yy] = lev[u.ff][u.ss] + 1;
                q.push(mp(xx, yy));
            }
        }
        if (lev[disx][disy] != -1)
            break;
    }
    return lev[disx][disy];
}
int solve(int x, int y)
{
    disx = x;
    disy = y;
    int ans = 0;
    For(i, sou.sz)
    {
        int tem = bfs(sou[i].ff.ff, sou[i].ff.ss);
        if (tem == -1)
            return inf;
        ans += tem / sou[i].ss;
        if (tem % sou[i].ss)
            ans++;
    }
    return ans;
}
int main()
{
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        v.clr;
        sou.clr;
        sff(n, m);
        For(i, n)
        {
            cin >> s;
            v.pb(s);
            For(j, s.sz) if (s[j] != '.')
                sou.pb(mp(mp(i, j), s[j] - '0'));
        }
        int ans = inf;
        For(i, n)
            For(j, m)
                ans = min(solve(i, j), ans);
        CASE(cs++);
        if (ans == inf)
            ans = -1;
        pfn(ans);
    }
    return 0;
}
