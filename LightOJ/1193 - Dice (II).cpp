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
#define mod 100000007
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
int s, n, k;
i64 f(int pos, int sum)
{
    if (sum > s)
        return 0;
    if (pos == n)
    {
        if (sum == s)
            return 1;
        return 0;
    }
    i64 ans = 0;
    Fre(i, 1, k + 1)
        ans += f(pos + 1, sum + i) * i;
    return ans;
}
i64 dp[2][15000 * 2 + 10];
//i64 dpPrint[100][200];
void table_calc()
{
    //        mem(dp,0);
    //        mem(dpPrint,0);
    For(i, 2)
        For(j, s + k + 1)
            dp[i][j] = 0;
    dp[n % 2][s] = 1;
    //        dpPrint[ n ][ s ] = 1;
    for (int row = n - 1; row >= 0; row--)
    {
        i64 cellAns = 0;
        i64 cumSum = 0;
        int thisRow = row % 2;
        int nextRow = (row + 1) % 2;
        Fre(i, 1, k + 1)
        {
            cellAns += (dp[nextRow][i] * i) % mod;
            if (cellAns > mod)
                cellAns %= mod;
            cumSum += dp[nextRow][i];
            if (cumSum > mod)
                cumSum %= mod;
        }
        For(col, s + 1)
        {
            dp[thisRow][col] = cellAns;
            //                        dpPrint[ row ][col] = cellAns;
            cellAns -= cumSum;
            cellAns += mod;
            if (cellAns > mod)
                cellAns %= mod;
            cellAns += dp[nextRow][col + k + 1] * k;
            if (cellAns > mod)
                cellAns %= mod;
            cumSum += dp[nextRow][col + k + 1];
            if (cumSum > mod)
                cumSum %= mod;
            cumSum -= dp[nextRow][col + 1];
            cumSum += mod;
            if (cumSum > mod)
                cumSum %= mod;
        }
    }
}
int main()
{
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        sfff(n, k, s);
        //                cout << f(0,0) << endl;
        //
        //
        //
        //                For(i,n+1)
        //                {
        //                        For(j,s+1)
        //                                printf("%4d", f(i,j));
        //
        //                        puts("");
        //                }
        //
        //                table_calc();
        //
        //                For(i,n+1)
        //                {
        //                        For(j,s+1)
        //                                printf("%4d", dpPrint[i][j]);
        //
        //                        puts("");
        //                }
        table_calc();
        CASE(cs++);
        printf("%lld\n", dp[0][0]);
    }
    return 0;
}
