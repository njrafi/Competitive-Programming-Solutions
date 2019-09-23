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
vpi v;
vector<i64> cum;
int x1, x2;
int f(int i, int x, int xx)
{
    int need = x / v[i].ff;
    if (x % v[i].ff)
        need++;
    if (i + need >= cum.sz)
        return -1;
    //        cerr << "index " << i << endl;
    //        cerr << v[i].ff << " " << need << " " << i+need << endl;
    //        cerr << cum[i+need] - cum[i] << endl;
    int lo = i + need, hi = cum.sz - 2, ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (cum[mid] - cum[i] >= x)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    if (ans == -1)
        return -1;
    //        cerr << ans << endl;
    int baki = v.sz - ans;
    need = xx / v[ans].ff;
    if (xx % v[ans].ff)
        need++;
    if (need > baki)
        return -1;
    if (cum.back() - cum[ans] >= xx)
    {
        //                cerr << "gg" << endl;
        return ans;
    }
}
int main()
{
    cum.pb(0);
    int n, x1, x2, inp;
    sfff(n, x1, x2);
    Fre(i, 1, n + 1)
    {
        sf(inp);
        v.pb(mp(inp, i));
    }
    sort(all(v));
    For(i, v.sz)
    {
        cum.pb(cum.back() + v[i].ff);
        //                cout << v[i].ff << " ";
    }
    //        cout << endl;
    vi v1, v2;
    For(i, v.sz)
    {
        if (f(i, x1, x2) != -1)
        {
            puts("Yes");
            int gg = f(i, x1, x2);
            cout << gg - i << " " << v.sz - gg << endl;
            Fre(j, i, gg)
                    cout
                << v[j].ss << " ";
            cout << endl;
            Fre(j, gg, v.sz)
                    cout
                << v[j].ss << " ";
            cout << endl;
            return 0;
        }
        if (f(i, x2, x1) != -1)
        {
            puts("Yes");
            int gg = f(i, x2, x1);
            cout << v.sz - gg << " " << gg - i << endl;
            Fre(j, gg, v.sz)
                    cout
                << v[j].ss << " ";
            cout << endl;
            Fre(j, i, gg)
                    cout
                << v[j].ss << " ";
            cout << endl;
            return 0;
        }
    }
    puts("No");
    return 0;
}
