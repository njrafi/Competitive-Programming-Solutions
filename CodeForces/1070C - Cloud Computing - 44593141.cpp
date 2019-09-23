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
#define mxn 1000006
pair<i64, i64> tree[4 * mxn];
void update(int n, int st, int en, int idx, int val)
{
    if (st == en)
    {
        tree[n].ff += val;
        tree[n].ss += (i64)val * st;
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    if (idx <= mid)
        update(lc, st, mid, idx, val);
    else
        update(rc, mid + 1, en, idx, val);
    tree[n].ff = tree[lc].ff + tree[rc].ff;
    tree[n].ss = tree[lc].ss + tree[rc].ss;
}
pair<i64, i64> query(int n, int st, int en, int l, int r)
{
    if (r < st || en < l)
        return {0, 0};
    if (l <= st && en <= r)
        return tree[n];
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    pair<i64, i64> q1 = query(lc, st, mid, l, r);
    pair<i64, i64> q2 = query(rc, mid + 1, en, l, r);
    q1.ff += q2.ff;
    q1.ss += q2.ss;
    return q1;
}
int query_cum(int n, int st, int en, int rem)
{
    if (st == en)
        return st;
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    //        cout << "in tree " << n << " " << tree[lc].ff << " " << tree[rc].ff << " " << rem << endl;
    if (rem <= tree[lc].ff)
        return query_cum(lc, st, mid, rem);
    else
        return query_cum(rc, mid + 1, en, rem - tree[lc].ff);
}
vector<pii> ll[mxn], rr[mxn];
void ins(pii gg)
{
    //        cout << "inserting " << gg.ff << " at " << gg.ss << endl;
    update(1, 1, mxn, gg.ss, gg.ff);
}
void rem(pii gg)
{
    //        cout << "removing " << gg.ff << " at " << gg.ss << endl;
    update(1, 1, mxn, gg.ss, -gg.ff);
}
int main()
{
    int n, k, m, l, r, p, c;
    sfff(n, k, m);
    while (m--)
    {
        sff(l, r);
        sff(c, p);
        ll[l].pb({c, p});
        rr[r].pb({c, p});
    }
    i64 ret = 0;
    Fre(i, 1, n + 1)
    {
        For(j, ll[i].sz)
            ins(ll[i][j]);
        i64 tot = query(1, 1, mxn, 1, mxn).ff;
        //                cout << i << " e total server " << tot << endl;
        if (tot < k)
        {
            ret += query(1, 1, mxn, 1, mxn).ss;
            //                        cout << i << " e na kina cost" << " " << query(1,1,mxn,1,mxn).ss << endl;
        }
        else
        {
            int ans = query_cum(1, 1, mxn, k);
            //                        cout << i << " e query kore peyechi " << ans << endl;
            i64 totCost = query(1, 1, mxn, 1, ans).ss - query(1, 1, mxn, ans, ans).ss;
            i64 totNow = query(1, 1, mxn, 1, ans).ff - query(1, 1, mxn, ans, ans).ff;
            i64 need = k - totNow;
            totCost += need * ans;
            //                        cout << i << " e cost" << totCost << endl;
            ret += totCost;
        }
        For(j, rr[i].sz)
            rem(rr[i][j]);
        //                cout << i << " " << ret << endl;
        //                getchar();
        //                getchar();
    }
    cout << ret << endl;
    return 0;
}
