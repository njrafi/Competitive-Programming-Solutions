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
bool checkbit(int mask, int bit) { return mask & (1 << bit); }
int setbit(int mask, int bit) { return mask | (1 << bit); }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int n;
vpi v;
bool valid(int x, int y)
{
    For(i, v.sz) if (v[i].ff == x || abs(v[i].ff - x) == abs(v[i].ss - y)) return 0;
    return 1;
}
int cost(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return 0;
    if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
        return 1;
    return 2;
}
vector<vpi> boards;
void f(int pos)
{
    if (v.sz == n)
    {
        boards.pb(v);
        return;
    }
    For(i, n) if (valid(i, pos))
    {
        v.pb(mp(i, pos));
        f(pos + 1);
        v.pop_back();
    }
}
int idx;
int dp[8][(1 << 8) + 2];
int vis[8][(1 << 8) + 2];
int lala;
int f(int pos, int mask)
{
    if (pos == 8)
        return 0;
    if (vis[pos][mask] == lala)
        return dp[pos][mask];
    vis[pos][mask] = lala;
    int ans = inf;
    For(i, 8) if (!checkbit(mask, i))
    {
        int nmask = setbit(mask, i);
        int gg = cost(v[pos].ff, v[pos].ss, boards[idx][i].ff, boards[idx][i].ss);
        ans = min(ans, f(pos + 1, nmask) + gg);
    }
    return dp[pos][mask] = ans;
}
int main()
{
    n = 8;
    f(0);
    //        cout << boards.sz << endl;
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        char ss[10];
        v.clr;
        For(i, 8)
        {
            scanf("%s", ss);
            For(j, 8) if (ss[j] == 'q')
                v.pb({i, j});
        }
        int ans = inf;
        For(i, boards.sz)
        {
            idx = i;
            lala++;
            ans = min(ans, f(0, 0));
        }
        CASE(cs++);
        pfn(ans);
    }
    return 0;
}
