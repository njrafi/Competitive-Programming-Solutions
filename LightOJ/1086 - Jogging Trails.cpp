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
i64 po(i64 a, i64 b)
{
    i64 ans = 1;
    while (b--)
        ans *= a;
    return ans;
}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
bool checkbit(int mask, int bit) { return mask & (1 << bit); }
int setbit(int mask, int bit) { return mask | (1 << bit); }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int deg[20], dis[20][20];
int lim;
int dp[20][(1 << 16) + 10];
int n;
int cs = 1;
int vis[20][(1 << 16) + 10];
void floyd()
{
    Fre(k, 1, n + 1)
        Fre(i, 1, n + 1)
            Fre(j, 1, n + 1)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int f(int node, int mask)
{
    if (node == n + 1)
        return 0;
    if (vis[node][mask] == -1)
        return dp[node][mask];
    int ans = inf;
    vis[node][mask] = cs;
    if (deg[node] % 2 == 0 || checkbit(mask, node))
        ans = f(node + 1, mask);
    else
    {
        for (int i = node + 1; i <= n; i++)
            if (deg[i] % 2)
            {
                int nmask = setbit(mask, i);
                ans = min(ans, f(node + 1, nmask) + dis[node][i]);
            }
    }
    return dp[node][mask] = ans;
}
int main()
{
    //        cout << fixed <<  15*15*po(2,15) << endl;
    int t, m, a, b, c;
    fastRead(&t);
    while (t--)
    {
        mem(deg, 0);
        Fre(i, 1, 20)
            Fre(j, 1, 20) if (i == j)
                dis[i][j] = 0;
        else dis[i][j] = inf;
        fastRead(&n);
        fastRead(&m);
        int ans = 0;
        while (m--)
        {
            fastRead(&a);
            fastRead(&b);
            fastRead(&c);
            ans += c;
            deg[a]++;
            deg[b]++;
            dis[a][b] = min(dis[a][b], c);
            dis[b][a] = min(dis[b][a], c);
        }
        floyd();
        CASE(cs++);
        fastWrite(f(1, 0) + ans);
    }
    return 0;
}
