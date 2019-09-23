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
#define CASE(a) printf("Case %d:\n", a)
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
struct info
{
    int cost, fuel, node;
};
class cmp
{
public:
    bool operator()(info a, info b)
    {
        //                if(a.cost==b.cost)
        //                        return a.fuel < b.fuel;
        return a.cost > b.cost;
    }
};
#define mxn 102
int fuelCost[102];
int dis[mxn][mxn];
/// node,fuel
vpi v[mxn];
int dij(int st, int en, int cap)
{
    For(i, mxn)
        For(j, mxn)
            dis[i][j] = inf;
    priority_queue<info, vector<info>, cmp> p;
    dis[st][0] = 0;
    p.push({0, 0, st});
    while (!p.empty())
    {
        info u = p.top();
        p.pop();
        if (dis[u.node][u.fuel] < u.cost)
            continue;
        if (u.node == en)
            return u.cost;
        For(i, v[u.node].sz)
        {
            int vv = v[u.node][i].ff;
            int vNeed = v[u.node][i].ss;
            for (int i = max(u.fuel, vNeed); i <= cap; i++)
            {
                int buyCost = (i - u.fuel) * fuelCost[u.node];
                int newFuel = i - vNeed;
                if (dis[vv][newFuel] > dis[u.node][u.fuel] + buyCost)
                {
                    dis[vv][newFuel] = dis[u.node][u.fuel] + buyCost;
                    p.push({dis[vv][newFuel], newFuel, vv});
                }
            }
        }
    }
    return inf;
}
int main()
{
    int t, cs = 1, n, m, q, a, b, c;
    sf(t);
    while (t--)
    {
        mem(v, NULL);
        sff(n, m);
        For(i, n)
            sf(fuelCost[i]);
        while (m--)
        {
            sfff(a, b, c);
            v[a].pb(mp(b, c));
            v[b].pb(mp(a, c));
        }
        CASE(cs++);
        sf(q);
        while (q--)
        {
            sfff(c, a, b);
            int ans = dij(a, b, c);
            if (ans == inf)
                puts("impossible");
            else
                pfn(ans);
        }
    }
    return 0;
}
