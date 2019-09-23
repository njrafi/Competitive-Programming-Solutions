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
#define mxn 100005
vi v[mxn], soja[mxn], ulta[mxn];
int p[mxn][22], root, n;
int l[mxn];
i64 totDown[mxn][22];
i64 totUp[mxn][22];
i64 sum;
// p[x][y] means 2^y th parent of x
// tot[x][y] means the total cost in the path of 2^y th parent
// pathsize will give us the number of edges between u and v
void input()
{
    int a, b, c, d;
    mem(v, NULL);
    mem(soja, NULL);
    mem(ulta, NULL);
    sum = 0;
    root = 1;
    sf(n);
    For(i, n - 1)
    {
        sfff(a, b, c);
        sf(d);
        sum += c + d;
        v[a].pb(b);
        soja[a].pb(c);
        ulta[a].pb(d);
        v[b].pb(a);
        soja[b].pb(d);
        ulta[b].pb(c);
    }
}
// determing the level of the nodes
void dfs(int s, int par, int lev, int pedgeSoja, int pedgeUlta)
{
    p[s][0] = par;
    totUp[s][0] = pedgeUlta;
    totDown[s][0] = pedgeSoja;
    l[s] = lev;
    For(i, v[s].sz) if (l[v[s][i]] == -1)
        dfs(v[s][i], s, lev + 1, soja[s][i], ulta[s][i]);
}
void gen_table()
{
    mem(p, -1);
    mem(l, -1);
    dfs(root, -1, 0, inf, inf);
    // (1<<j) = po(2,j)
    for (int j = 1; (1 << j) < n; j++)
        Fre(i, 1, n + 1) if (p[i][j - 1] != -1)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
            totUp[i][j] = totUp[p[i][j - 1]][j - 1] + totUp[i][j - 1];
            totDown[i][j] = totDown[p[i][j - 1]][j - 1] + totDown[i][j - 1];
        }
}
/// uu up, vv down
i64 query(int uu, int vv)
{
    i64 total = 0;
    // bring both node to same level
    int hi;
    if (l[uu] >= l[vv])
    {
        hi = log2(l[uu]) + 2;
        for (int i = hi; i >= 0; i--)
            if (l[uu] - (1 << i) >= l[vv])
            {
                total += totUp[uu][i];
                uu = p[uu][i];
            }
    }
    else
    {
        hi = log2(l[vv]) + 2;
        for (int i = hi; i >= 0; i--)
            if (l[vv] - (1 << i) >= l[uu])
            {
                total += totDown[vv][i];
                vv = p[vv][i];
            }
    }
    if (uu == vv)
        return total;
    for (int i = hi; i >= 0; i--)
        if (p[uu][i] != -1 && p[uu][i] != p[vv][i])
        {
            total += totUp[uu][i];
            uu = p[uu][i];
            total += totDown[vv][i];
            vv = p[vv][i];
        }
    //        cout << "lca" << " " << p[uu][0] << endl;
    total += totUp[uu][0] + totDown[vv][0];
    return total;
}
int main()
{
    int t, q, st, en;
    sf(t);
    while (t--)
    {
        input();
        gen_table();
        sf(q);
        while (q--)
        {
            sff(st, en);
            //                        pfn(query(st,en));
            cout << sum - query(en, st) << endl;
        }
    }
    return 0;
}
