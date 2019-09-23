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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including treegg_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define mxn 20004
#define lag 6000
ordered_set treegg[4 * mxn];
vpi hor[mxn]; // y , size
int hudai;
void add(int n, int st, int en, int idx, int val)
{
    if (st == en)
    {
        treegg[n].insert({val, hudai++});
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    if (idx <= mid)
        add(lc, st, mid, idx, val);
    else
        add(rc, mid + 1, en, idx, val);
    treegg[n].insert({val, hudai++});
    return;
}
int query(int n, int st, int en, int l, int r, int i, int j)
{
    if (en < l || st > r)
        return 0;
    if (l <= st && en <= r)
        return treegg[n].order_of_key({j, inf}) - treegg[n].order_of_key({i, -inf});
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    return query(lc, st, mid, l, r, i, j) + query(rc, mid + 1, en, l, r, i, j);
}
vector<pair<pii, int>> ver;
bool sortgg(pair<pii, int> a, pair<pii, int> b)
{
    return a.ss < b.ss;
}
int main()
{
    int n, x1, y1, x2, y2;
    sf(n);
    while (n--)
    {
        sff(x1, y1);
        sff(x2, y2);
        if (y1 > y2)
            swap(y1, y2);
        y1 += lag;
        y2 += lag;
        x1 += lag;
        x2 += lag;
        if (x1 == x2)
            ver.pb({{y1, y2}, x1});
        else
            hor[min(x1, x2)].pb({y1, max(x1, x2)});
    }
    //        build(1,1,mxn);
    sort(all(ver), sortgg);
    int ok = 0;
    i64 ans = 0;
    For(i, ver.sz)
    {
        Fre(j, ok + 1, ver[i].ss + 1)
            For(k, hor[j].sz)
                add(1, 1, mxn, hor[j][k].ff, hor[j][k].ss);
        //                cout << "updated " << ok +1 << " " << ver[i].ss << endl;
        ok = ver[i].ss;
        Fre(j, i + 1, ver.sz)
        {
            int st = max(ver[i].ff.ff, ver[j].ff.ff);
            int en = min(ver[i].ff.ss, ver[j].ff.ss);
            int sss = max(ver[j].ss, ver[i].ss);
            //                        cout << "printing: " << endl;
            //                        cout << ver[i].ss << " " << ver[i].ff.ff - lag << " " << ver[i].ff.ss - lag << endl;
            //                        cout << ver[j].ss << " " << ver[j].ff.ff - lag << " " << ver[j].ff.ss - lag << endl;
            i64 gg = query(1, 1, mxn, st, en, sss, inf);
            //                        cout << gg << endl;
            ans += (gg * (gg - 1)) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}
