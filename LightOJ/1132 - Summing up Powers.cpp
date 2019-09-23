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
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define mod 10007
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
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
// http://lightoj.com/volume_showproblem.php?problem=1096
unsigned int dp[55][55];
bool vis[55][55];
unsigned int ncr(i64 n, i64 r)
{
    if (!r)
        return 1;
    if (n == r)
        return 1;
    if (r == 1)
        return n;
    if (vis[n][r])
        return dp[n][r];
    vis[n][r] = 1;
    return dp[n][r] = ncr(n - 1, r) + ncr(n - 1, r - 1);
}
struct matrix
{
    unsigned int mat[55][55], row, col;
    matrix()
    {
        mem(mat, 0);
    }
};
matrix mul(matrix a, matrix b)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
    For(i, r.row)
        For(j, r.col)
    {
        unsigned int sum = 0;
        For(k, a.col)
            sum += (a.mat[i][k] * b.mat[k][j]);
        r.mat[i][j] = sum;
    }
    return r;
}
matrix power(matrix a, i64 p)
{
    //        cout << p << endl;
    if (p == 1)
        return a;
    matrix r = power(a, p / 2);
    if (p % 2 == 1)
        return mul(a, mul(r, r));
    else
        return mul(r, r);
}
matrix setval(int k)
{
    matrix r = matrix();
    r.row = r.col = k + 2;
    r.mat[0][0] = 1;
    //        cout << "gg" << 1 << endl;
    i64 tem = k;
    Fre(i, 1, r.col)
    {
        r.mat[0][i] = ncr(k, tem);
        tem--;
    }
    //        cout << "gg" << 2 << endl;
    Fre(i, 1, r.row)
    {
        r.mat[i][0] = 0;
        i64 tem = k;
        Fre(j, i, r.col)
        {
            r.mat[i][j] = ncr(k, tem);
            tem--;
        }
        k--;
    }
    return r;
}
void print(matrix m)
{
    For(i, m.row)
    {
        For(j, m.col)
            pfs(m.mat[i][j]);
        puts("");
    }
}
int main()
{
    int t, cs = 1;
    i64 n, k;
    sf(t);
    while (t--)
    {
        fastRead(&n);
        fastRead(&k);
        CASE(cs++);
        if (n == 1)
        {
            puts("1");
            continue;
        }
        matrix bm = setval(k);
        //                puts("gg 1");
        //                print(bm);
        matrix res = power(bm, n - 1);
        //                puts("gg 2");
        unsigned int ans = 0;
        For(i, res.col)
            ans += res.mat[0][i];
        //                print(res);
        i64 ret = ans;
        //
        fastWrite(ret);
        //                cout << ans << endl;
    }
    return 0;
}
