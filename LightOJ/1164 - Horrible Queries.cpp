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
#define pfn(n) printf("%lld\n", n)
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
#define CASE(a) printf("Case %d:\n", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
//matrix rot(matrix a){matrix res;res.row = a.col;res.col = a.row;For(i,a.row)For(j,a.col)res.mat[j][a.row-i-1] = a.mat[i][j];return res;}
#define max_n 100005
i64 v[max_n], tree[4 * max_n], lazy[4 * max_n];
void build(int i, int s, int e)
{
    if (s == e)
        tree[i] = v[s];
    else
    {
        int mid = (s + e) / 2;
        build(2 * i, s, mid);
        build(2 * i + 1, mid + 1, e);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}
void process(int i, int s, int e, int val)
{
    tree[i] += (e - s + 1) * val;
    if (s != e)
    {
        lazy[2 * i] += val;
        lazy[2 * i + 1] += val;
    }
}
void update(int i, int s, int e, int l, int r, int val)
{
    if (lazy[i])
    {
        process(i, s, e, lazy[i]);
        lazy[i] = 0;
    }
    if (e < l || s > r)
        return;
    if (l <= s && e <= r)
        process(i, s, e, val);
    else
    {
        int mid = (s + e) / 2;
        update(2 * i, s, mid, l, r, val);
        update(2 * i + 1, mid + 1, e, l, r, val);
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}
i64 query(int i, int s, int e, int l, int r)
{
    if (e < l || s > r)
        return 0;
    if (lazy[i])
    {
        process(i, s, e, lazy[i]);
        lazy[i] = 0;
    }
    if (l <= s && e <= r)
        return tree[i];
    else
    {
        int mid = (s + e) / 2;
        return query(2 * i, s, mid, l, r) + query(2 * i + 1, mid + 1, e, l, r);
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int t, n, q, op, l, r, val, c = 1;
    sf(t);
    while (t--)
    {
        mem(v, 0);
        mem(lazy, 0);
        sff(n, q);
        build(1, 0, n - 1);
        CASE(c++);
        while (q--)
        {
            sf(op);
            if (!op)
            {
                sfff(l, r, val);
                update(1, 0, n - 1, l, r, val);
            }
            else
            {
                sff(l, r);
                pfn(query(1, 0, n - 1, l, r));
            }
        }
    }
    return 0;
}
