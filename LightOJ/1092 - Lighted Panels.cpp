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
int togglebit(int mask, int bit) { return mask ^ (1 << bit); }
/// premask i er jnno move :3
vi pre[300];
/// change of ith mask for jth move
int change[300][300];
/// bits of i
int cost[300];
int tar;
void precalc(int tot)
{
    mem(pre, NULL);
    tar = (1 << tot) - 1;
    For(preMask, 1 << tot)
    {
        For(mask, 1 << tot)
        {
            int tem = preMask;
            For(i, tot) if (checkbit(mask, i))
            {
                tem = togglebit(tem, i);
                if (i - 1 >= 0)
                    tem = togglebit(tem, i - 1);
                if (i + 1 < tot)
                    tem = togglebit(tem, i + 1);
            }
            change[preMask][mask] = tem;
            cost[mask] = __builtin_popcount(mask);
            if (tem == tar)
                pre[preMask].pb(mask);
        }
        //                cout << pre[preMask].sz << " ";
    }
    //        puts("");
}
vi v;
int m;
int dp[9][260][260];
int vis[9][260][260];
int cs;
int f(int pos, int mask, int preMask)
{
    if (pos == v.sz - 1)
    {
        if (preMask == tar)
            return 0;
        return inf;
    }
    if (vis[pos][mask][preMask] == cs)
        return dp[pos][mask][preMask];
    vis[pos][mask][preMask] = cs;
    int nextMask = v[pos + 1];
    int ans = inf;
    if (!pos)
    {
        For(moveGG, 1 << m)
            ans = min(ans, f(pos + 1, change[nextMask][moveGG], change[mask][moveGG]) + cost[moveGG]);
    }
    else
    {
        For(i, pre[preMask].sz)
        {
            int moveGG = pre[preMask][i];
            ans = min(ans, f(pos + 1, change[nextMask][moveGG], change[mask][moveGG]) + cost[moveGG]);
        }
    }
    return dp[pos][mask][preMask] = ans;
}
int main()
{
    int t, n;
    char s[10];
    sf(t);
    while (t--)
    {
        v.clr;
        sff(n, m);
        For(i, n)
        {
            scanf("%s", s);
            int tem = 0;
            For(j, m) if (s[j] == '*')
                tem = setbit(tem, j);
            v.pb(tem);
        }
        v.pb(0);
        precalc(m);
        //                mem(dp,-1);
        cs++;
        int ans = f(0, v[0], 0);
        CASE(cs);
        if (ans == inf)
            puts("impossible");
        else
            pfn(ans);
        //                cout <<  << endl;
    }
    return 0;
}
