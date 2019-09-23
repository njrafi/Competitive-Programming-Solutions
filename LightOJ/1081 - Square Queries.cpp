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
#define mxn 505
/// max x range and y range
int max_x;
int max_y;
struct node
{
    /// For minimum,maximum ans sum
    int mn, mx, sum;
    node()
    {
        mn = inf;
        mx = -inf;
        sum = 0;
    }
    node(int val)
    {
        mx = mn = sum = val;
    }
};
node tree[4 * mxn][4 * mxn];
int grid[mxn][mxn];
/// merging node
node merge(node a, node b)
{
    a.mn = min(a.mn, b.mn);
    a.mx = max(a.mx, b.mx);
    a.sum += b.sum;
    return a;
}
/*
v = vertex of seg tree
l = left range
r = right range
*/
/// Building col
void build_y(int nx, int stx, int enx, int ny, int sty, int eny)
{
    if (sty == eny)
    {
        if (stx == enx)
            tree[nx][ny] = node(grid[stx][sty]);
        else
            tree[nx][ny] = merge(tree[nx * 2][ny], tree[nx * 2 + 1][ny]);
        //                cout << nx << " " << ny << " " << tree[nx][ny].sum << endl;
        return;
    }
    int mid = (sty + eny) / 2, lc = 2 * ny, rc = lc + 1;
    build_y(nx, stx, enx, lc, sty, mid);
    build_y(nx, stx, enx, rc, mid + 1, eny);
    tree[nx][ny] = merge(tree[nx][lc], tree[nx][rc]);
    //        cout << nx << " " << ny << " " << tree[nx][ny].sum << endl;
    //        cout << stx << " " << enx << " " << sty << " " << eny << ": " << endl;
    //        cout << tree[nx][ny].sum << " " << tree[nx][ny].mn << " " << tree[nx][ny].mx << endl << endl;
}
/// Building row seg trees
void build_x(int nx, int stx, int enx)
{
    //        cout << nx << " " << stx << " " << enx << endl;
    if (stx != enx)
    {
        int mid = (stx + enx) / 2, lc = 2 * nx, rc = lc + 1;
        build_x(lc, stx, mid);
        build_x(rc, mid + 1, enx);
    }
    build_y(nx, stx, enx, 1, 1, max_y);
}
/// Updating col seg trees
void update_y(int nx, int stx, int enx, int ny, int sty, int eny, int x, int y, int val)
{
    if (sty == eny)
    {
        if (stx == enx)
            tree[nx][ny] = node(val);
        else
            tree[nx][ny] = merge(tree[nx * 2][ny], tree[nx * 2 + 1][ny]);
        return;
    }
    int mid = (sty + eny) / 2, lc = 2 * ny, rc = lc + 1;
    if (y <= mid)
        update_y(nx, stx, enx, lc, sty, mid, x, y, val);
    else
        update_y(nx, stx, enx, rc, mid + 1, eny, x, y, val);
    tree[nx][ny] = merge(tree[nx][lc], tree[nx][rc]);
}
/// Updating row seg trees
void update_x(int nx, int stx, int enx, int x, int y, int val)
{
    if (stx != enx)
    {
        int mid = (stx + enx) / 2, lc = 2 * nx, rc = lc + 1;
        if (x <= mid)
            update_x(lc, stx, mid, x, y, val);
        else
            update_x(rc, mid + 1, enx, x, y, val);
    }
    update_y(nx, stx, enx, 1, 1, max_y, x, y, val);
}
node query_y(int nx, int ny, int sty, int eny, int ly, int ry)
{
    if (ly > ry || eny < ly || ry < sty)
        return node();
    if (ly <= sty && eny <= ry)
    {
        return tree[nx][ny];
    }
    int mid = (sty + eny) / 2, lc = 2 * ny, rc = lc + 1;
    node q1 = query_y(nx, lc, sty, mid, ly, ry);
    node q2 = query_y(nx, rc, mid + 1, eny, ly, ry);
    return merge(q1, q2);
}
/// Querying from [lx,ly] to [rx,ry] rectangle
node query_x(int nx, int stx, int enx, int lx, int rx, int ly, int ry)
{
    if (lx > rx || enx < lx || rx < stx)
        return node();
    if (lx <= stx && enx <= rx)
    {
        return query_y(nx, 1, 1, max_y, ly, ry);
    }
    int mid = (stx + enx) / 2, lc = 2 * nx, rc = lc + 1;
    node q1 = query_x(lc, stx, mid, lx, rx, ly, ry);
    node q2 = query_x(rc, mid + 1, enx, lx, rx, ly, ry);
    return merge(q1, q2);
}
///Helper funtions
/// Build the tree
void build()
{
    build_x(1, 1, max_x);
}
/// update grid[x][y] to val
void update(int x, int y, int val)
{
    update_x(1, 1, max_x, x, y, val);
}
/// Query from [lx,ly] to [rx,ry]
node query(int lx, int rx, int ly, int ry)
{
    //        cout << "calling" << endl;
    //        cout << lx << " " << rx << " " << ly << " " << ry << endl;
    return query_x(1, 1, max_x, lx, rx, ly, ry);
}
int main()
{
    int t, cs = 1, q, x, y, s;
    sf(t);
    while (t--)
    {
        sff(max_x, q);
        max_y = max_x;
        Fre(i, 1, max_x + 1)
            Fre(j, 1, max_y + 1)
        {
            sf(grid[i][j]);
            update(i, j, grid[i][j]);
        }
        //                build();
        CASE(cs++);
        while (q--)
        {
            sfff(x, y, s);
            node gg = query(x, x + s - 1, y, y + s - 1);
            pfn(gg.mx);
            //                        cout << gg.mx << " " << gg.mn << " " << gg.sum << endl;
        }
    }
    return 0;
}
