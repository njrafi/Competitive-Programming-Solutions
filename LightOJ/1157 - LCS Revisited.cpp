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
#define mod 1000007
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
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 1003
int dp[mxn][mxn];
int dp2[mxn][mxn];
int vis[mxn][mxn];
int vis2[mxn][mxn];
int cs = 1;
int s1sz, s2sz;
char s1[mxn], s2[mxn];
int f(int i, int j)
{
    if (i == s1sz || j == s2sz)
        return 0;
    if (vis[i][j] == cs)
        return dp[i][j];
    vis[i][j] = cs;
    int ans = 0;
    if (s1[i] == s2[j])
        ans = 1 + f(i + 1, j + 1);
    ans = max(ans, max(f(i + 1, j), f(i, j + 1)));
    return dp[i][j] = ans;
}
int nxt[2][30][mxn];
void pre()
{
    Fre(k, 'a', 'z' + 1)
    {
        nxt[0][k - 'a'][s1sz] = inf;
        for (int i = s1sz - 1; i >= 0; i--)
            if (s1[i] == k)
                nxt[0][k - 'a'][i] = i;
            else
                nxt[0][k - 'a'][i] = nxt[0][k - 'a'][i + 1];
    }
    Fre(k, 'a', 'z' + 1)
    {
        nxt[1][k - 'a'][s2sz] = inf;
        for (int i = s2sz - 1; i >= 0; i--)
            if (s2[i] == k)
                nxt[1][k - 'a'][i] = i;
            else
                nxt[1][k - 'a'][i] = nxt[1][k - 'a'][i + 1];
    }
}
int f2(int i, int j)
{
    if (!f(i, j))
        return 1;
    if (vis2[i][j] == cs)
        return dp2[i][j];
    vis2[i][j] = cs;
    int ans = 0;
    For(k, 26)
    {
        int x = nxt[0][k][i];
        int y = nxt[1][k][j];
        if (x == inf || y == inf)
            continue;
        if (f(x, y) == f(i, j))
            ans += f2(x + 1, y + 1);
        //                ans %= mod;
    }
    return dp2[i][j] = ans % mod;
}
int main()
{
    int t;
    char ss[1003];
    sf(t);
    while (t--)
    {
        scanf("%s %s", s1, s2);
        s1sz = strlen(s1);
        s2sz = strlen(s2);
        //                cin >> s1 >> s2;
        pre();
        //                mem(dp,-1);
        //                mem(dp2,-1);
        CASE(cs++);
        //                cout <<f(0,0) << endl;
        pfn(f2(0, 0));
    }
    return 0;
}
