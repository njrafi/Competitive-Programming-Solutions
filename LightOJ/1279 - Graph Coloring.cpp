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
#define inf INT_MAX / 2
#define infll LLONG_MAX / 3
#define For(i, n) for (int i = 0; i < n; i++)
#define Fre(i, a, b) for (int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define EPS 1e-8
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
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
i64 bigmod(i64 num, i64 n, i64 mod)
{
    if (n == 0)
        return 1;
    i64 x = bigmod(num, n / 2, mod);
    x = x * x % mod;
    if (n % 2 == 1)
        x = x * num % mod;
    return x;
}
i64 modinverse(i64 num, i64 mod)
{
    return bigmod(num, mod - 2, mod) % mod;
}
i64 a[105][100]; // contains the coeff,ans included
int node, k;
int where[105];
vi v[105];
i64 calc()
{
    i64 pp = 0;
    For(i, node) if (where[i] == -1)
        pp++;
    return bigmod(k, pp, 1000000007);
}
i64 gauss()
{
    int n = node;   // row size
    int m = node;   // col size
    mem(where, -1); // where[i] = -1 , row i zero, var i independent
    for (int col = 0, row = 0; col < m && row < n; ++col)
    {
        int sel = row;
        if (!a[sel][col])
        {
            for (int i = row; i < n; ++i)
                if (a[i][col] > a[sel][col])
                {
                    sel = i;
                    break;
                }
        }
        if (!a[sel][col]) // col zero of
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;
        for (int i = row + 1; i < n; ++i)
        {
            i64 c = (a[i][col] * modinverse(a[row][col], k)) % k;
            for (int j = col; j <= m; ++j)
                a[i][j] = (a[i][j] - (a[row][j] * c) % k + k) % k;
        }
        ++row;
    }
    //        ans.assign (m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] == -1 && a[i][m])
            return 0;
    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return calc();
    return 1;
}
void a_calc()
{
    For(i, node)
    {
        a[i][i] = (-1 + k) % k;
        For(j, v[i].sz)
        {
            int tem = v[i][j];
            a[i][tem] = 1;
        }
    }
    //        For(i,node)
    //        {
    //                For(j,node+1)
    //                        cout << a[i][j];
    //                cout << endl;
    //        }
}
int main()
{
    int t, m, cs = 1, x, y;
    sf(t);
    while (t--)
    {
        mem(v, NULL);
        mem(a, 0);
        sfff(node, m, k);
        while (m--)
        {
            sff(x, y);
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
        }
        a_calc();
        CASE(cs++);
        printf("%lld\n", gauss());
    }
    return 0;
}
