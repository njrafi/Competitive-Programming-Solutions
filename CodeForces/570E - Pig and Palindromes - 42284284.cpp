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
bool adjacent(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return 1;
    if (x1 + 1 == x2 && y1 == y2)
        return 1;
    if (x1 == x2 && y1 + 1 == y2)
        return 1;
    return 0;
}
bool valid(int x, int y)
{
    if (x >= 0 && y >= 0 && x < v.sz && y < v[0].sz)
        return 1;
    return 0;
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
i64 dp[505][505][3];
int nxt;
i64 f(int x1, int x2, int stp)
{
    int y1 = stp - x1;
    int y2 = v[0].sz - 1 - (stp - (v.sz - 1 - x2));
    //        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << stp << " " << nxt << endl;
    if (!valid(x1, y1) || !valid(x2, y2) || v[x1][y1] != v[x2][y2])
        return dp[x1][x2][stp & 1] = 0;
    //        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << stp << " " << nxt << endl;
    //        if(nxt==stp)
    //        {
    if (x1 > x2 || y1 > y2)
        return dp[x1][x2][stp & 1] = 0;
    if (adjacent(x1, y1, x2, y2))
        return dp[x1][x2][stp & 1] = 1;
    //        }
    i64 ans = 0;
    For(i, 2)
        Fre(j, 2, 4)
    {
        int xx1 = x1 + dx[i];
        int yy1 = y1 + dy[i];
        int xx2 = x2 + dx[j];
        int yy2 = y2 + dy[j];
        if (valid(xx1, yy1) && valid(xx2, yy2) && v[xx1][yy1] == v[xx2][yy2])
        {
            //                                cout << f(xx1,xx2,stp+1) << endl;
            ans += dp[xx1][xx2][(stp + 1) & 1];
        }
    }
    //        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << ans << endl;
    return dp[x1][x2][stp & 1] = ans % mod;
}
char ss[505];
int main()
{
    int n, m;
    string s;
    sff(n, m);
    For(i, n)
    {
        scanf("%s", ss);
        s = ss;
        v.pb(s);
    }
    //        cout << f(0,v.sz-1,0) << endl;
    for (int stp = 502; stp >= 0; stp--)
    {
        nxt = stp + 1;
        For(i, n)
            For(j, n)
                f(i, j, stp);
    }
    cout << dp[0][v.sz - 1][0] << endl;
    return 0;
}
