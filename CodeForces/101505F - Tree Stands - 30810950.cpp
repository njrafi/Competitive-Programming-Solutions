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
#define mxn 202
vi v[mxn];
int rs[mxn], fc[mxn]; /// rs = right sibling , fc = first children
bool vis[mxn];
i64 dp[mxn][mxn][4];
void dfs(int s)
{
    vis[s] = 1;
    vi tem;
    For(i, v[s].sz) if (!vis[v[s][i]])
        tem.pb(v[s][i]);
    if (tem.sz)
        fc[s] = tem[0];
    For(i, tem.sz)
    {
        //                dbg(tem.sz-1);
        if (i + 1 < tem.sz)
            rs[tem[i]] = tem[i + 1];
    }
    For(i, tem.sz)
        dfs(tem[i]);
}
i64 f(int pos, int k, int par)
{
    //        cout << pos << " " << k << " " << par << endl;
    if (!k)
    {
        if (par == 1)
            return 0;
        else
            return 1;
    }
    if (dp[pos][k][par] != -1)
        return dp[pos][k][par];
    i64 ans = 0;
    if (rs[pos] && fc[pos])
    {
        if (!par)
        {
            For(i, k - 1 + 1) // boshaia
                ans = (ans + (f(fc[pos], i, 1) * f(rs[pos], k - 1 - i, 0)) % mod) % mod;
            //                        dbg(11);
            //                        cout << pos << " " << k << " " << par << " " << ans << endl;
            For(i, k + 1) // na boshaia
                ans = (ans + (f(fc[pos], i, 0) * f(rs[pos], k - i, 0)) % mod) % mod;
            //                        dbg(22);
            //                        cout << pos << " " << k << " " << par << " " << ans << endl;
        }
        else if (par == 1)
        {
            For(i, k - 1 + 1) // boshaia
                ans = (ans + (f(fc[pos], i, 2) * f(rs[pos], k - 1 - i, 2)) % mod) % mod;
            //                        dbg(11);
            //                        cout << pos << " " << k << " " << par << " " << ans << endl;
            For(i, k + 1) // na boshaia
                ans = (ans + (f(fc[pos], i, 0) * f(rs[pos], k - i, 1)) % mod) % mod;
            //                        dbg(22);
            //                        cout << pos << " " << k << " " << par << " " << ans << endl;
        }
        else
        {
            For(i, k - 1 + 1) // boshaia
                ans = (ans + (f(fc[pos], i, 2) * f(rs[pos], k - 1 - i, 2)) % mod) % mod;
            //                        dbg(11);
            //                        cout << pos << " " << k << " " << par << " " << ans << endl;
            For(i, k + 1) // na boshaia
                ans = (ans + (f(fc[pos], i, 0) * f(rs[pos], k - i, 2)) % mod) % mod;
            //
            //                         dbg(22);
            //                        cout << pos << " " << k << " " << par << " " << ans << endl;
        }
    }
    else if (rs[pos])
    {
        if (!par)
            ans = f(rs[pos], k, 0);
        else if (par == 1)
            ans = (f(rs[pos], k - 1, 2) + f(rs[pos], k, 1)) % mod;
        else
            ans = (f(rs[pos], k - 1, 2) + f(rs[pos], k, 2)) % mod;
    }
    else if (fc[pos])
    {
        if (!par)
            ans = (f(fc[pos], k - 1, 1) + f(fc[pos], k, 0)) % mod;
        else if (par == 1)
            ans = f(fc[pos], k - 1, 2);
        else
            ans = (f(fc[pos], k - 1, 2) + f(fc[pos], k, 0)) % mod;
    }
    else
    {
        if (par && k == 1)
            ans = 1;
    }
    //        cout << pos << " " << k << " " << par << " " << ans << endl;
    return dp[pos][k][par] = ans;
}
int main()
{
    int n, k, a, b;
    while (sff(n, k) != EOF)
    {
        mem(v, NULL);
        For(i, n - 1)
        {
            sff(a, b);
            v[a].pb(b);
            v[b].pb(a);
        }
        mem(vis, 0);
        mem(rs, 0);
        mem(fc, 0);
        dfs(1);
        mem(dp, -1);
        //                Fre(i,1,n+1)
        //                        cout << i << " " << fc[i] << " " << rs[i] << endl;
        cout << f(1, k, 0) << endl;
    }
    /*
4 3
1 2
2 4
2 3
*/
    /*
4 2
1 2
1 3
2 4
*/
    return 0;
}
