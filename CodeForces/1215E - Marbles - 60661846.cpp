#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define vpi vector<pii>
#define mpi map<int, int>
#define i64 long long int
#define endl '\n'
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
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
// bit manipulations
bool checkbit(int mask, int bit) { return mask & (1 << bit); }
int setbit(int mask, int bit) { return mask | (1 << bit); }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 22
#define lim (1 << 22) - 1
vi v[mxn];
vi w;
i64 invCnt[mxn][mxn];
i64 dp[lim + 100];
i64 lastMask;
i64 f(int mask)
{
    if (mask == lastMask)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    i64 ans = infll;
    Fre(i, 1, 21) if (!checkbit(mask, i) && checkbit(lastMask, i))
    {
        int nmask = setbit(mask, i);
        i64 now = 0;
        Fre(j, 1, 21) if (i != j && checkbit(mask, j))
            now += invCnt[j][i];
        ans = min(ans, now + f(nmask));
    }
    return dp[mask] = ans;
}
int main()
{
    int n, inp;
    sf(n);
    For(i, n)
    {
        sf(inp);
        v[inp].pb(i);
        w.pb(inp);
        lastMask = setbit(lastMask, inp);
    }
    For(j, w.sz)
        Fre(i, 1, 21)
            invCnt[w[j]][i] += v[i].end() - lower_bound(all(v[i]), j);
    mem(dp, -1);
    cout << f(0) << endl;
    return 0;
}
