#include <bits/stdtr1c++.h>
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
inline void fastRead(int *a)
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
inline void fastWrite(int a)
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
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define MAX 52
#define MAXIMIZE +1
#define MINIMIZE -1
#define inf (~0U >> 1)
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
/// From Zahin Vai Library
/// Complexity is O(n^3)
/// But in reality n = 1000 worked in less than 1 sec in kattis
using namespace std;
namespace wm
{ /// hash = 581023
bool visited[MAX];
int U[MAX], V[MAX], P[MAX], way[MAX], minv[MAX], match[MAX], ar[MAX][MAX];
/// n = number of row and m = number of columns in 1 based, flag = MAXIMIZE or MINIMIZE
/// match[i] contains the column to which row i is matched
int hungarian(int n, int m, int mat[MAX][MAX], int flag)
{
    clr(U), clr(V), clr(P), clr(ar), clr(way);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ar[i][j] = mat[i][j];
            if (flag == MAXIMIZE)
                ar[i][j] = -ar[i][j];
        }
    }
    if (n > m)
        m = n;
    int i, j, a, b, c, d, r, w;
    for (i = 1; i <= n; i++)
    {
        P[0] = i, b = 0;
        for (j = 0; j <= m; j++)
            minv[j] = inf, visited[j] = false;
        do
        {
            visited[b] = true;
            a = P[b], d = 0, w = inf;
            for (j = 1; j <= m; j++)
            {
                if (!visited[j])
                {
                    r = ar[a][j] - U[a] - V[j];
                    if (r < minv[j])
                        minv[j] = r, way[j] = b;
                    if (minv[j] < w)
                        w = minv[j], d = j;
                }
            }
            for (j = 0; j <= m; j++)
            {
                if (visited[j])
                    U[P[j]] += w, V[j] -= w;
                else
                    minv[j] -= w;
            }
            b = d;
        } while (P[b] != 0);
        do
        {
            d = way[b];
            P[b] = P[d], b = d;
        } while (b != 0);
    }
    for (j = 1; j <= m; j++)
        match[P[j]] = j;
    return (flag == MINIMIZE) ? -V[0] : V[0];
}
} // namespace wm
int mat[MAX][MAX];
int main()
{
    int t, cs = 1, n;
    fastRead(&t);
    while (t--)
    {
        sf(n);
        Fre(i, 1, n + 1)
            Fre(j, 1, n + 1)
                fastRead(&mat[i][j]);
        CASE(cs++);
        fastWrite(wm::hungarian(n, n, mat, MAXIMIZE));
    }
}
