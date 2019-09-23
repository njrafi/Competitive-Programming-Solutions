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
#define vll vector<i64>
#define si set<int>
#define vs vector<string>
#define pii pair<int, int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int, vector<int>, greater<int>>
#define mpi map<int, int>
#define i64 unsigned long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
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
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
inline void fastRead(i64 *a)
{
    register char c = 0;
    while (c < 33)
        c = gc();
    *a = 0;
    while (c > 33)
    {
        *a = *a * 10 + c - '0';
        c = gc();
    }
}
inline void fastWrite(i64 a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc('\n');
}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
i64 po(i64 a, i64 b)
{
    i64 ans = 1;
    while (b--)
        ans *= a;
    return ans;
}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
struct matrix
{
    i64 mat[4][4], row, col;
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
//finding a*b % m
matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
    For(i, r.row)
        For(j, r.col)
    {
        i64 sum = 0;
        For(k, a.col)
            sum = (sum + a.mat[i][k] * b.mat[k][j]);
        r.mat[i][j] = sum;
    }
    return r;
}
// finding a^p % m
matrix power(matrix a, i64 p)
{
    if (!p)
        return identity(a);
    if (p == 1)
        return a;
    if (p % 2 == 1)
        return multiply(a, power(a, p - 1));
    matrix r = power(a, p / 2);
    r = multiply(r, r);
    return r;
}
matrix setvalue(i64 p, i64 q)
{
    matrix r;
    r.row = r.col = 2;
    r.mat[0][0] = p;
    r.mat[0][1] = -q;
    r.mat[1][0] = 1;
    r.mat[1][1] = 0;
    return r;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int t, cs = 1;
    i64 p, q, n;
    sf(t);
    while (t--)
    {
        fastRead(&p);
        fastRead(&q);
        fastRead(&n);
        matrix bm = setvalue(p, q);
        CASE(cs++);
        if (!n)
            pfn(2);
        else if (n == 1)
            pfn(p);
        else
        {
            bm = power(bm, n - 1);
            //                               print(bm);
            i64 two = 2;
            fastWrite(bm.mat[0][0] * p + bm.mat[0][1] * two);
        }
    }
    return 0;
}
