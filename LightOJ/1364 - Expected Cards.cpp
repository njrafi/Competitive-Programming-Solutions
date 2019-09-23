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
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int areq, breq, creq, dreq;
int vis[16][16][16][16][5][5];
double dp[16][16][16][16][5][5];
int cs;
double f(int a, int b, int c, int d, int j1, int j2)
{
    int rema = 13 - a + (j1 == 1) + (j2 == 1);
    int remb = 13 - b + (j1 == 2) + (j2 == 2);
    int remc = 13 - c + (j1 == 3) + (j2 == 3);
    int remd = 13 - d + (j1 == 4) + (j2 == 4);
    int remj = (!j1) + (!j2);
    int rem = (rema + remb + remc + remd + remj);
    //        cout << a << " " << b << " " << c << " " << d << endl;
    //        cout << rem << endl;
    if (a >= areq && b >= breq && c >= creq && d >= dreq)
        return 0;
    if (!rem)
        return inf;
    if (vis[a][b][c][d][j1][j2] == cs)
        return dp[a][b][c][d][j1][j2];
    vis[a][b][c][d][j1][j2] = cs;
    double ans = 1;
    if (rema)
        ans += rema * f(a + 1, b, c, d, j1, j2) / rem;
    if (remb)
        ans += remb * f(a, b + 1, c, d, j1, j2) / rem;
    if (remc)
        ans += remc * f(a, b, c + 1, d, j1, j2) / rem;
    if (remd)
        ans += remd * f(a, b, c, d + 1, j1, j2) / rem;
    if (!j1)
    {
        double tem = f(a + 1, b, c, d, 1, j2);
        tem = min(tem, f(a, b + 1, c, d, 2, j2));
        tem = min(tem, f(a, b, c + 1, d, 3, j2));
        tem = min(tem, f(a, b, c, d + 1, 4, j2));
        ans += remj * tem / rem;
    }
    else if (!j2)
    {
        double tem = f(a + 1, b, c, d, j1, 1);
        tem = min(tem, f(a, b + 1, c, d, j1, 2));
        tem = min(tem, f(a, b, c + 1, d, j1, 3));
        tem = min(tem, f(a, b, c, d + 1, j1, 4));
        ans += remj * tem / rem;
    }
    //        cout << a << " " << b << " " << c << " " <<d << " " << j1 << " " << j2 << " " <<  ans << endl;
    return dp[a][b][c][d][j1][j2] = ans;
}
int main()
{
    int t;
    sf(t);
    while (t--)
    {
        cin >> areq >> breq >> creq >> dreq;
        cs++;
        //                cout << f(0,0,0,0,0,0) << endl;
        double ans = f(0, 0, 0, 0, 0, 0);
        CASE(cs);
        if (ans > 60)
            puts("-1");
        else
            cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
