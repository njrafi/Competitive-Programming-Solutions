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
vpi v, w;
vector<pair<pii, int>> vv, ww;
pii cc[100005], cw[100005];
void gen_cum()
{
    int mx = 0, mx2 = 0, mxid = -1, mx2id = -1;
    For(i, 100005)
    {
        cc[i].ff = -1;
        cc[i].ss = -1;
    }
    For(i, vv.sz)
    {
        int p = vv[i].ff.ff;
        int b = vv[i].ff.ss;
        if (b >= mx)
        {
            mx2 = mx;
            mx2id = mxid;
            mx = b;
            mxid = vv[i].ss;
        }
        else if (b > mx2)
        {
            mx2 = b;
            mx2id = vv[i].ss;
        }
        cc[p].ff = mxid;
        cc[p].ss = mx2id;
    }
    mx = -1;
    mx2 = -1;
    For(i, 100005)
    {
        if (cc[i].ff != -1)
        {
            mx = cc[i].ff;
            mx2 = cc[i].ss;
        }
        cc[i].ff = mx;
        cc[i].ss = mx2;
    }
    mx = 0, mx2 = 0, mxid = -1, mx2id = -1;
    For(i, 100005)
    {
        cw[i].ff = -1;
        cw[i].ss = -1;
    }
    For(i, ww.sz)
    {
        int p = ww[i].ff.ff;
        int b = ww[i].ff.ss;
        if (b >= mx)
        {
            mx2 = mx;
            mx2id = mxid;
            mx = b;
            mxid = ww[i].ss;
        }
        else if (b > mx2)
        {
            mx2 = b;
            mx2id = ww[i].ss;
        }
        cw[p].ff = mxid;
        cw[p].ss = mx2id;
    }
    mx = -1;
    mx2 = -1;
    For(i, 100005)
    {
        if (cw[i].ff != -1)
        {
            mx = cw[i].ff;
            mx2 = cw[i].ss;
        }
        cw[i].ff = mx;
        cw[i].ss = mx2;
    }
    /*
        For(i,31)
        {
                cout << i << ":" << endl;
                int id1 = cw[i].ff;
                int id2 = cw[i].ss;
                 cout << id1 << " " << w[id1].ff << " " << w[id1].ss << endl;
                cout << id2 << " " << w[id2].ff << " " << w[id2].ss << endl;
        }
        */
}
int f1(int c)
{
    int mx = 0;
    for (int i = vv.sz - 1; i >= 0; i--)
    {
        int p = vv[i].ff.ff;
        int b = vv[i].ff.ss;
        int id = vv[i].ss;
        if (cc[c - p].ff == -1)
            continue;
        if (cc[c - p].ff != id)
        {
            b += v[cc[c - p].ff].ss;
            mx = max(b, mx);
        }
        else if (cc[c - p].ss != -1)
        {
            b += v[cc[c - p].ss].ss;
            mx = max(b, mx);
        }
    }
    return mx;
}
int f2(int c)
{
    int mx = 0;
    for (int i = ww.sz - 1; i >= 0; i--)
    {
        int p = ww[i].ff.ff;
        int b = ww[i].ff.ss;
        int id = ww[i].ss;
        if (cw[c - p].ff == -1)
            continue;
        if (cw[c - p].ff != id)
        {
            b += w[cw[c - p].ff].ss;
            mx = max(b, mx);
        }
        else if (cw[c - p].ss != -1)
        {
            b += w[cw[c - p].ss].ss;
            mx = max(b, mx);
        }
    }
    return mx;
}
int main()
{
    int n, c, d, a, b, mx1 = 0, mx2 = 0;
    string s;
    sfff(n, c, d);
    For(i, n)
    {
        sff(a, b);
        cin >> s;
        if (s[0] == 'C' && b <= c)
        {
            v.pb(mp(b, a));
            vv.pb(mp(mp(b, a), (int)v.sz - 1));
            mx1 = max(mx1, a);
        }
        else if (s[0] == 'D' && b <= d)
        {
            w.pb(mp(b, a));
            ww.pb(mp(mp(b, a), (int)w.sz - 1));
            mx2 = max(mx2, a);
        }
    }
    sort(all(vv));
    sort(all(ww));
    int ans = 0;
    if (!vv.empty() && !ww.empty())
    {
        ans += mx1;
        ans += mx2;
    }
    gen_cum();
    ans = max(ans, f1(c));
    ans = max(ans, f2(d));
    cout << ans << endl;
    return 0;
}
