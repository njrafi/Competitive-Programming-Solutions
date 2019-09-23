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
#define mxn 50005
vi v[mxn], vt[mxn], top, vv[mxn];
vpi edge;
int vis[mxn], com[mxn], sccsz[mxn], sccmn[mxn];
// sccsz contains the size of ith scc
// vv contains edge between scc's
// com cotains the which scc a node belongs
int tot; // number of SCC
bool in[mxn], out[mxn];
void topo(int s)
{
    vis[s] = 1;
    For(i, v[s].sz) if (!vis[v[s][i]])
        topo(v[s][i]);
    top.pb(s);
}
void dfs(int s, int val)
{
    vis[s] = 1;
    com[s] = val;
    For(i, vt[s].sz) if (!vis[vt[s][i]])
        dfs(vt[s][i], val);
}
int dfs2(int s)
{
    vis[s] = 1;
    int val = sccsz[s];
    For(i, vv[s].sz) if (!vis[vv[s][i]])
        val += dfs2(vv[s][i]);
    return val;
}
void ini()
{
    mem(v, NULL);
    mem(vt, NULL);
    edge.clr;
    top.clr;
    mem(vis, 0);
    For(i, mxn)
        sccmn[i] = inf;
    mem(vv, NULL);
    mem(sccsz, 0);
    tot = 1;
}
int main()
{
    int t, n, m, a, b, cs = 1;
    sf(t);
    while (t--)
    {
        ini();
        sf(n);
        For(i, n)
        {
            sff(a, b);
            edge.pb(mp(a, b));
            v[a].pb(b);
            vt[b].pb(a);
        }
        Fre(i, 1, n + 1) if (!vis[i])
            topo(i);
        reverse(all(top));
        mem(vis, 0);
        For(i, top.sz) if (!vis[top[i]])
            dfs(top[i], tot++);
        // cout << endl;
        Fre(i, 1, n + 1)
        {
            sccsz[com[i]]++;
            sccmn[com[i]] = min(sccmn[com[i]], i);
            // cout << i << " " << com[i] << endl;
        }
        // cout << endl;
        mem(in, 0);
        mem(out, 0);
        For(i, edge.sz)
        {
            a = edge[i].ff;
            b = edge[i].ss;
            if (com[a] != com[b])
            {
                // cout << com[a] << " " << com[b] << endl;
                vv[com[a]].pb(com[b]);
                out[com[a]] = 1;
                in[com[b]] = 1;
            }
        }
        vpi ans;
        Fre(i, 1, tot) if (!in[i])
        {
            mem(vis, 0);
            int tem = dfs2(i);
            ans.pb(mp(-tem, sccmn[i]));
            //cout << i << " " << tem << " " << sccsz[i] << " " << sccmn[i] << endl;
        }
        sort(all(ans));
        CASE(cs++);
        cout << ans[0].ss << endl;
    }
    return 0;
}
