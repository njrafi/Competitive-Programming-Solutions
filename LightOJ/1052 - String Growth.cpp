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
struct matrix
{
    i64 mat[3][3], row, col;
};
matrix identity(matrix a)
{
    For(i, a.row)
        For(j, a.row)
    {
        if (i == j)
            a.mat[i][j] = 1;
        else
            a.mat[i][j] = 0;
    }
    return a;
}
void print(matrix a)
{
    For(i, a.row)
    {
        For(j, a.col)
                cout
            << a.mat[i][j] << " ";
        cout << endl;
    }
}
matrix multiply(matrix a, matrix b, i64 m)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
    For(i, r.row)
        For(j, r.col)
    {
        i64 sum = 0;
        For(k, a.col)
            sum = (sum + (a.mat[i][k] * b.mat[k][j])) % m;
        r.mat[i][j] = sum;
    }
    return r;
}
// finding a^p
matrix power(matrix a, int p, i64 m)
{
    if (!p)
        return identity(a);
    if (p == 1)
        return a;
    if (p % 2 == 1)
        return multiply(a, power(a, p - 1, m), m);
    matrix r = power(a, p / 2, m);
    r = multiply(r, r, m);
    return r;
}
matrix setvalue()
{
    matrix r;
    r.row = r.col = 2;
    r.mat[0][0] = r.mat[0][1] = r.mat[1][0] = 1;
    r.mat[1][1] = 0;
    return r;
}
i64 fib(int n)
{
    if (!n)
        return 0;
    else if (n == 1)
        return 1;
    matrix bm = setvalue();
    bm = power(bm, n - 1, mod);
    return (bm.mat[0][0]) % mod;
}
i64 ff[100];
void pre()
{
    ff[1] = 1;
    ff[2] = 1;
    Fre(i, 3, 70)
        ff[i] = ff[i - 1] + ff[i - 2];
}
int solve(i64 a, i64 b, i64 c, i64 d, i64 e, i64 f, i64 k)
{
    i64 dd = a * e - b * d;
    if (!dd)
        return -1;
    i64 xup = c * e - b * f;
    i64 yup = a * f - c * d;
    if (xup % dd || yup % dd)
        return -1;
    i64 x = xup / dd;
    i64 y = yup / dd;
    if (x < 0 || y < 0)
        return -1;
    return (x * fib(k) + y * fib(k + 1)) % mod;
}
int main()
{
    pre();
    int t, n, x, m, y, k, cs = 1;
    sf(t);
    while (t--)
    {
        sff(n, x);
        sfff(m, y, k);
        CASE(cs++);
        if (n > 50 || m > 50 || ff[n] > inf || ff[m] > inf)
        {
            puts("Impossible");
            continue;
        }
        int ans = solve(ff[n], ff[n + 1], x, ff[m], ff[m + 1], y, k);
        if (ans == -1)
            puts("Impossible");
        else
            pfn(ans);
    }
    return 0;
}
