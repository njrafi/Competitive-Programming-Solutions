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
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
vi totMasks;
vi v[(1 << 16) + 5];
int n;
int val[17][(1 << 16) + 5];
int grid[17][17];
bool valid(int mask)
{
    For(i, n - 1) if (checkbit(mask, i) && checkbit(mask, i + 1)) return 0;
    return 1;
}
bool valid2(int mask, int mask2)
{
    For(i, n) if (checkbit(mask2, i))
    {
        int ok = 0;
        if (i - 1 < 0 || !checkbit(mask, i - 1))
            ok++;
        if (!checkbit(mask, i))
            ok++;
        if (i >= n || !checkbit(mask, i + 1))
            ok++;
        if (ok != 3)
            return 0;
    }
    return 1;
}
void pre()
{
    mem(v, NULL);
    totMasks.clr;
    mem(val, 0);
    For(i, 1 << n) if (valid(i))
        totMasks.pb(i);
    //        cout << totMasks.sz << endl;
    int ans = 0;
    For(i, totMasks.sz)
        For(j, totMasks.sz) if (valid2(totMasks[i], totMasks[j]))
    {
        ans++;
        //                                cout << totMasks[i] << " " << totMasks[j] << endl;
        v[totMasks[i]].pb(totMasks[j]);
    }
    //        cout << ans << endl;
    For(i, n)
        For(j, totMasks.sz)
    {
        int mask = totMasks[j];
        For(k, n) if (checkbit(mask, k))
            val[i][mask] += grid[k][i];
    }
}
int dp[17][(1 << 16) + 5];
int vis[17][(1 << 17) + 5];
int cs;
int f(int pos, int mask)
{
    if (pos == n)
        return 0;
    if (vis[pos][mask] == cs)
        return dp[pos][mask];
    vis[pos][mask] = cs;
    int ans = -inf;
    For(i, v[mask].sz)
    {
        int nmask = v[mask][i];
        ans = max(ans, f(pos + 1, nmask) + val[pos][nmask]);
    }
    return dp[pos][mask] = ans;
}
int main()
{
    int t;
    sf(t);
    while (t--)
    {
        sf(n);
        For(i, n)
            For(j, n)
                sf(grid[i][j]);
        pre();
        cs++;
        cout << f(0, 0) << endl;
    }
    return 0;
}