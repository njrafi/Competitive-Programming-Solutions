#include <stdio.h>
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
#define MAX 8002
using namespace std;
/// 2 SAT (1 based index for variables)
/// Each variable can have two possible values (true or false)
/// Variables must satisfy a system of constraints on pairs of variables
namespace sat
{
bool visited[MAX * 2];
vi adj[MAX * 2], rev[MAX * 2];
int n, m, l, dfs_t[MAX * 2], order[MAX * 2], parent[MAX * 2];
inline int neg(int x)
{
    return ((x) <= n ? (x + n) : (x - n));
}
/// Call init once
void init(int nodes)
{
    n = nodes, m = nodes * 2;
    for (int i = 0; i < MAX * 2; i++)
    {
        adj[i].clear();
        rev[i].clear();
    }
}
/// Add implication, if a then b
inline void add_implication(int a, int b)
{
    if (a < 0)
        a = n - a;
    if (b < 0)
        b = n - b;
    adj[a].push_back(b);
    rev[b].push_back(a);
}
inline void add_or(int a, int b)
{
    add_implication(-a, b);
    add_implication(-b, a);
}
inline void add_xor(int a, int b)
{
    add_or(a, b);
    add_or(-a, -b);
}
inline void add_and(int a, int b)
{
    add_or(a, b);
    add_or(a, -b);
    add_or(-a, b);
}
/// force variable x to be true (if x is negative, force !x to be true)
inline void force_true(int x)
{
    if (x < 0)
        x = n - x;
    add_implication(neg(x), x);
}
/// force variable x to be false (if x is negative, force !x to be false)
inline void force_false(int x)
{
    if (x < 0)
        x = n - x;
    add_implication(x, neg(x));
}
inline void topsort(int i)
{
    visited[i] = true;
    int j, x, len = rev[i].size();
    for (j = 0; j < len; j++)
    {
        x = rev[i][j];
        if (!visited[x])
            topsort(x);
    }
    dfs_t[i] = ++l;
}
inline void dfs(int i, int p)
{
    parent[i] = p;
    visited[i] = true;
    int j, x, len = adj[i].size();
    for (j = 0; j < len; j++)
    {
        x = adj[i][j];
        if (!visited[x])
            dfs(x, p);
    }
}
void build()
{
    int i, x;
    mem(visited, 0);
    for (i = m, l = 0; i >= 1; i--)
    {
        if (!visited[i])
        {
            topsort(i);
        }
        order[dfs_t[i]] = i;
    }
    mem(visited, 0);
    for (i = m; i >= 1; i--)
    {
        x = order[i];
        if (!visited[x])
        {
            dfs(x, x);
        }
    }
}
/// Returns true if the system is 2-satisfiable and returns the solution (nodes set to true) in vector res
bool satisfy(vi &res)
{
    build();
    mem(visited, 0);
    for (int i = 1; i <= m; i++)
    {
        int x = order[i];
        if (parent[x] == parent[neg(x)])
            return false;
        if (!visited[parent[x]])
        {
            visited[parent[x]] = true;
            visited[parent[neg(x)]] = false;
        }
    }
    res.clr;
    for (int i = 1; i <= n; i++)
        if (visited[parent[i]])
            res.push_back(i);
    return true;
}
} // namespace sat
int main()
{
    int t, n, m, a, b, cs = 1;
    sf(t);
    while (t--)
    {
        sff(n, m);
        sat::init(m);
        while (n--)
        {
            sff(a, b);
            sat::add_or(a, b);
        }
        vi ans;
        bool ok = sat::satisfy(ans);
        CASE(cs++);
        if (ok)
        {
            puts("Yes");
            printf("%d", ans.sz);
            For(i, ans.sz)
                printf(" %d", ans[i]);
            puts("");
        }
        else
            puts("No");
    }
    return 0;
}
