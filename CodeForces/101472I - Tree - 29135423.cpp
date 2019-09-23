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
#define pfn(n) printf("%d", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-7
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define READ freopen("I.IN", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d", i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 50005
vpi v[mxn];
vpi dp[mxn];
int vis[mxn];
int ret[mxn];
int dfs(int s)
{
    vis[s] = 1;
    int ans = 0;
    For(i, v[s].sz)
    {
        int vv = v[s][i].ff;
        int ww = v[s][i].ss;
        if (!vis[vv])
        {
            int tem = dfs(vv) + ww;
            ans = max(tem, ans);
            dp[s].pb(mp(-tem, vv));
        }
    }
    sort(all(dp[s]));
    return ans;
}
/*
6
1 5 3
2 6 3
6 1 1
1 3 5
4 6 4
*/
void dfs2(int s, int par, int paredge)
{
    vis[s] = 1;
    if (par != -1)
    {
        int mx = 0;
        For(i, dp[par].sz) if (dp[par][i].ss != s)
        {
            mx = -dp[par][i].ff;
            break;
        }
        int tem = mx + paredge;
        dp[s].pb(mp(-tem, par));
        sort(all(dp[s]));
    }
    For(i, v[s].sz)
    {
        int vv = v[s][i].ff;
        int ww = v[s][i].ss;
        if (!vis[vv])
            dfs2(vv, s, ww);
    }
}
int main()
{
    READ;
    int n, a, b, c;
    sf(n);
    For(i, n - 1)
    {
        sfff(a, b, c);
        v[a].pb(mp(b, c));
        v[b].pb(mp(a, c));
    }
    dfs(1);
    mem(vis, 0);
    dfs2(1, -1, -1);
    Fre(i, 1, n + 1)
            cout
        << -dp[i][0].ff << endl;
    return 0;
}