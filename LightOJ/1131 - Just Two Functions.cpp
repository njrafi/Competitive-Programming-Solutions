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
#define CASE(a) printf("Case %d:\n", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
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
    int mat[10][10], row, col;
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
matrix multiply(matrix a, matrix b, int m)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
    For(i, r.row)
        For(j, r.col)
    {
        int sum = 0;
        For(k, a.col)
            sum = (sum + (a.mat[i][k] * b.mat[k][j])) % m;
        r.mat[i][j] = sum;
    }
    return r;
}
// finding a^p
matrix power(matrix a, int p, int m)
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
matrix setvalue(int a1, int b1, int c1, int a2, int b2, int c2)
{
    matrix r;
    r.row = r.col = 6;
    For(i, 6)
        For(j, 6)
            r.mat[i][j] = 0;
    r.mat[0][0] = a1;
    r.mat[0][1] = b1;
    r.mat[0][5] = c1;
    r.mat[3][2] = c2;
    r.mat[3][3] = a2;
    r.mat[3][4] = b2;
    r.mat[1][0] = r.mat[2][1] = r.mat[4][3] = r.mat[5][4] = 1;
    return r;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int t, cs = 1;
    int yo = po(2, 31) - 1;
    cin >> t;
    while (t--)
    {
        int a1, b1, c1, a2, b2, c2, seed[10], m, n, q;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        matrix bm = setvalue(a1, b1, c1, a2, b2, c2);
        //  print(bm);
        for (int i = 2; i >= 0; i--)
            cin >> seed[i];
        for (int i = 5; i >= 3; i--)
            cin >> seed[i];
        cin >> m >> q;
        CASE(cs++);
        while (q--)
        {
            cin >> n;
            if (n < 3)
                cout << seed[2 - n] % m << " " << seed[5 - n] % m << endl;
            else
            {
                matrix ans = power(bm, n - 2, m);
                // print(ans);
                i64 ans1 = 0;
                For(i, 6)
                    ans1 = (ans1 + (ans.mat[0][i] * seed[i]) % m) % m;
                cout << ans1 << " ";
                ans1 = 0;
                For(i, 6)
                    ans1 = (ans1 + (ans.mat[3][i] * seed[i]) % m) % m;
                cout << ans1 << endl;
            }
        }
    }
    return 0;
}
