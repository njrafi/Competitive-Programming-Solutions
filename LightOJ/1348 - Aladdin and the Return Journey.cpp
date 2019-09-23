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
//int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
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
//int bigmod(int num,int n){if(n==0)return 1;int x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//int modinverse(int num){return bigmod(num,mod-2)%mod;}
//int po(int a,int b){int ans=1;while(b--)ans *= a;return ans;}
//int ncr(int n,int r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
/// http://codeforces.com/blog/entry/12239
#define mxn 30005
int tree[4 * mxn];
void update(int n, int st, int en, int idx, int val)
{
    if (st == en)
    {
        tree[n] = val;
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    if (idx <= mid)
        update(lc, st, mid, idx, val);
    else
        update(rc, mid + 1, en, idx, val);
    tree[n] = tree[lc] + tree[rc];
}
int query(int n, int st, int en, int l, int r)
{
    if (r < st || en < l)
        return 0;
    if (l <= st && en <= r)
        return tree[n];
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    int q1 = query(lc, st, mid, l, r);
    int q2 = query(rc, mid + 1, en, l, r);
    return q1 + q2;
}
/// segtree ends///
int n;          /// node number
int par[mxn];   /// parent of nodes
int szz[mxn];   /// size of subtree
vi v[mxn];      /// The graph
int depth[mxn]; /// depth from root
int nxt[mxn];   /// Next node of the chain
    /// dfs to calculate the subtree size
void dfs(int n, int pp = 0)
{
    par[n] = pp;
    szz[n] = 1;
    For(i, v[n].sz)
    {
        int vv = v[n][i];
        if (vv == pp)
            continue;
        depth[vv] = depth[n] + 1;
        dfs(vv, n);
        szz[n] += szz[vv];
        /// next node of chain is the heaviest child
        if (nxt[n] == -1 || szz[vv] > szz[nxt[n]])
            nxt[n] = vv;
    }
}
int chain[mxn]; /// which chain a node belongs to
int num[mxn];   /// The changed node number
int csz[mxn];   /// chain i size
int top[mxn];   /// top node of the chain i
int cnt = 1;    /// the count of chains
int all;        /// For changing node numbers
                /// constructing chain
void hld(int n, int pp = -1)
{
    chain[n] = cnt - 1;
    num[n] = all++;
    /// if chain size zero top of the chain (cnt-1) is node n
    if (!csz[cnt - 1])
        top[cnt - 1] = n;
    csz[cnt - 1]++;
    /// go down this chain
    if (nxt[n] != -1)
        hld(nxt[n], n);
    For(i, v[n].sz)
    {
        int vv = v[n][i];
        if (vv == pp || vv == nxt[n])
            continue;
        cnt++;
        /// going the other child to build other chains
        hld(vv, n);
    }
}
int tot[mxn]; /// max of chain i
/// Getting result from a to b
/// For this problem we are getting max
int go(int a, int b)
{
    int ans = 0;
    while (chain[a] != chain[b])
    {
        /// we want the node with more depth chain in variable a
        if (depth[top[chain[a]]] < depth[top[chain[b]]])
            swap(a, b);
        int start = top[chain[a]];
        /// if full chain is included
        if (num[a] == num[start] + csz[chain[a]] - 1)
            ans += tot[chain[a]];
        else
            ans += query(1, 1, n, num[start], num[a]);
        a = par[start];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    ans += query(1, 1, n, num[a], num[b]);
    return ans;
}
/// changing value of node n to val or increase val
/// handle in the seg tree functions
void modify(int node, int val)
{
    update(1, 1, n, num[node], val);
    int st = num[top[chain[node]]];
    int en = st + csz[chain[node]] - 1;
    tot[chain[node]] = query(1, 1, n, st, en);
}
void ini()
{
    mem(nxt, -1);
    mem(v, NULL);
    mem(csz, 0);
    cnt = 2;
    all = 1;
}
int genie[mxn];
int main()
{
    int t, cs = 1, a, b, q, op;
    fastRead(&t);
    while (t--)
    {
        ini();
        fastRead(&n);
        Fre(i, 1, n + 1)
            fastRead(&genie[i]);
        For(i, n - 1)
        {
            fastRead(&a);
            fastRead(&b);
            a++;
            b++;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1);
        hld(1);
        Fre(i, 1, n + 1)
            modify(i, genie[i]);
        sf(q);
        CASE(cs++);
        while (q--)
        {
            fastRead(&op);
            fastRead(&a);
            fastRead(&b);
            a++;
            b++;
            if (op)
            {
                b--;
                modify(a, b);
            }
            else
                fastWrite(go(a, b));
        }
    }
    return 0;
}
