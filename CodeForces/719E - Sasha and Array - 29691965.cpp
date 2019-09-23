#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
using namespace std;
#define vi vector<int>
#define vll vector<i64>
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
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
#define infll LLONG_MAX / 3
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
//functions
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
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
#define mxn 100005
struct matrix
{
    int mat[2][2];
};
matrix base;
matrix iden;
matrix setvalue(int a, int b, int c, int d)
{
    matrix r;
    //        r.row = r.col = 2;
    r.mat[0][0] = a;
    r.mat[0][1] = b;
    r.mat[1][0] = c;
    r.mat[1][1] = d;
    return r;
}
void print(matrix a)
{
    For(i, 2)
    {
        For(j, 2)
                cout
            << a.mat[i][j] << " ";
        cout << endl;
    }
}
//finding a*b % m
matrix multiply(matrix a, matrix b)
{
    matrix r;
    For(i, 2)
        For(j, 2)
    {
        i64 sum = 0;
        For(k, 2)
        {
            sum += (i64)a.mat[i][k] * (i64)b.mat[k][j];
            if (sum > infll)
                sum %= mod;
        }
        if (sum > mod)
            sum %= mod;
        r.mat[i][j] = sum;
    }
    return r;
}
matrix add(matrix &a, matrix &b)
{
    matrix r;
    For(i, 2)
        For(j, 2)
    {
        r.mat[i][j] = a.mat[i][j] + b.mat[i][j];
        if (r.mat[i][j] > mod)
            r.mat[i][j] %= mod;
    }
    return r;
}
// finding a^p % m
matrix power(matrix a, i64 p)
{
    if (!p)
        return iden;
    if (p == 1)
        return a;
    if (p % 2 == 1)
        return multiply(a, power(a, p - 1));
    matrix r = power(a, p / 2);
    r = multiply(r, r);
    return r;
}
matrix nfib(i64 n)
{
    return power(base, n - 1);
}
vi v;
matrix tree[4 * mxn];
matrix lazy[4 * mxn];
bool lazyflag[4 * mxn];
void build(int n, int st, int en)
{
    if (st == en)
    {
        tree[n] = nfib(v[st]);
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    build(lc, st, mid);
    build(rc, mid + 1, en);
    tree[n] = add(tree[lc], tree[rc]);
}
void process(int n, int st, int en, matrix val)
{
    tree[n] = multiply(tree[n], val);
    //        lazy[n] = iden;
    lazyflag[n] = 0;
    int lc = 2 * n, rc = lc + 1;
    if (st != en)
    {
        if (!lazyflag[lc])
            lazy[lc] = val;
        else
            lazy[lc] = multiply(lazy[lc], val);
        if (!lazyflag[rc])
            lazy[rc] = val;
        else
            lazy[rc] = multiply(lazy[rc], val);
        lazyflag[lc] = 1;
        lazyflag[rc] = 1;
    }
}
void update(int n, int st, int en, int l, int r, i64 val)
{
    if (lazyflag[n])
        process(n, st, en, lazy[n]);
    if (en < l || r < st)
        return;
    if (l <= st && en <= r)
    {
        process(n, st, en, power(base, val));
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    update(lc, st, mid, l, r, val);
    update(rc, mid + 1, en, l, r, val);
    tree[n] = add(tree[lc], tree[rc]);
}
int query(int n, int st, int en, int l, int r)
{
    if (lazyflag[n])
        process(n, st, en, lazy[n]);
    if (en < l || r < st)
        return 0;
    if (l <= st && en <= r)
        return tree[n].mat[0][0];
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    int q1 = query(lc, st, mid, l, r);
    int q2 = query(rc, mid + 1, en, l, r);
    int ret = q1 + q2;
    if (ret > mod)
        ret %= mod;
    return ret;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n, q, inp, l, r, op;
    base = setvalue(1, 1, 1, 0);
    iden = setvalue(1, 0, 0, 1);
    //        For(i,4*mxn)
    //                lazy[i] = iden;
    sff(n, q);
    v.pb(1);
    For(i, n)
    {
        fastRead(&inp);
        v.pb(inp);
    }
    build(1, 1, n);
    For(j, q)
    {
        fastRead(&op);
        fastRead(&l);
        fastRead(&r);
        if (op == 1)
        {
            fastRead(&inp);
            update(1, 1, n, l, r, inp);
        }
        else
            fastWrite(query(1, 1, n, l, r));
    }
    return 0;
}