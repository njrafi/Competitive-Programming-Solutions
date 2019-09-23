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
#define mxn 200005
pair<i64, int> tree[4 * mxn];
i64 lazy[4 * mxn];
void process(int n, int st, int en, i64 val)
{
    tree[n].ff += val;
    lazy[n] = 0;
    int lc = 2 * n, rc = lc + 1;
    if (st != en)
    {
        lazy[lc] += val;
        lazy[rc] += val;
    }
    else
    {
        tree[n].ss = st;
    }
}
void update(int n, int st, int en, int l, int r, i64 val)
{
    if (l > r)
        return;
    process(n, st, en, lazy[n]);
    if (st > en || en < l || st > r)
        return;
    if (l <= st && en <= r)
    {
        process(n, st, en, val);
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    update(lc, st, mid, l, r, val);
    update(rc, mid + 1, en, l, r, val);
    if (tree[lc].ff < tree[rc].ff)
        tree[n] = tree[lc];
    else
        tree[n] = tree[rc];
}
pair<i64, int> query(int n, int st, int en, int l, int r)
{
    if (l > r)
        return {infll, -1};
    process(n, st, en, lazy[n]);
    if (st > en || en < l || st > r)
        return {infll, -1};
    if (l <= st && en <= r)
        return tree[n];
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    pair<i64, int> p1 = query(lc, st, mid, l, r);
    pair<i64, int> p2 = query(rc, mid + 1, en, l, r);
    if (p1.ff < p2.ff)
        return p1;
    else
        return p2;
}
int ans[mxn];
void gen(int n)
{
    vector<i64> v, w;
    For(i, n)
        v.pb(i + 1);
    random_shuffle(all(v));
    random_shuffle(all(v));
    For(i, v.sz)
            cout
        << v[i] << " ";
    cout << endl;
    For(i, v.sz)
    {
        int prev = 0;
        For(j, i) if (v[j] < v[i]) prev += v[j];
        w.pb(prev);
    }
    cout << n << endl;
    For(i, w.sz)
            cout
        << w[i] << " ";
    cout << endl;
    //        solve(w);
}
/*
22 1 4 7 20 13 29 12 9 16 27 18 3 17 25 28 26 23 24 14 11 5 21 6 15 30 10 19 8 2
30
0 0 1 5 12 12 67 12 12 46 104 62 1 65 142 194 167 142 165 49 24 8 150 13 85 396 35 161 26 1
*/
int main()
{
    //        gen(30);
    int n;
    i64 inp;
    sf(n);
    For(i, n)
    {
        cin >> inp;
        update(1, 0, n - 1, i, i, inp);
    }
    For(i, n)
    {
        //                cout << query(1,0,n-1,i,i).ff << " " << query(1,0,n-1,i,i).ss << endl;
    }
    For(i, n)
    {
        pair<i64, int> q = query(1, 0, n - 1, 0, n - 1);
        //                cout << i << " " << q.ff << " " << q.ss << endl;
        //                assert(q.ff == 0);
        //                assert(q.ss >= 0);
        ans[q.ss] = i + 1;
        update(1, 0, n - 1, q.ss + 1, n - 1, -(i + 1));
        update(1, 0, n - 1, q.ss, q.ss, infll);
    }
    For(i, n) pfs(ans[i]);
    return 0;
}
