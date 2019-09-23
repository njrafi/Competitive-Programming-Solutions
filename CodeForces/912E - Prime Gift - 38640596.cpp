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
#define infll LLONG_MAX / 10
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
i64 mx = 2000LL * 1000 * 1000 * 1000 * 1000 * 1000;
vi v;
vector<i64> tem;
vector<i64> v1, v2;
void back_t(int pos, i64 now)
{
    if (pos == v.sz)
    {
        tem.pb(now);
        return;
    }
    while (1)
    {
        back_t(pos + 1, now);
        if (now > mx / v[pos])
            break;
        now *= v[pos];
    }
}
i64 f(i64 lim)
{
    i64 ans = 0;
    int ridx = 0;
    For(i, v1.sz)
    {
        while (((double)v2[ridx] * (double)v1[i] > (lim + 100) || v2[ridx] * v1[i] > lim) && ridx < v2.sz)
            ridx++;
        //                cout << "debug" << " " << lim << endl;
        //                cout << i << " " << ridx << endl;
        ans += v2.sz - ridx;
    }
    //        cout <<
    return ans;
}
int main()
{
    //        cout << mx << endl;
    vi a;
    int n, inp;
    i64 k;
    sf(n);
    while (n--)
    {
        sf(inp);
        a.pb(inp);
    }
    cin >> k;
    for (int i = 0; i < a.sz; i += 2)
        v.pb(a[i]);
    back_t(0, 1);
    v1 = tem;
    v.clr;
    tem.clr;
    for (int i = 1; i < a.sz; i += 2)
        v.pb(a[i]);
    back_t(0, 1);
    v2 = tem;
    //
    //        For(i,v1.sz)
    //                cout << v1[i] << endl;
    //        cout << endl;
    //
    //        For(i,v2.sz)
    //                cout << v2[i] << endl;
    //        cout << endl;
    sort(all(v1));
    sort(all(v2));
    reverse(all(v2));
    i64 lo = 1, hi = mx / 2, ans;
    while (lo <= hi)
    {
        i64 mid = (lo + hi) / 2;
        //                cout << mid << " " << f(mid) << endl;
        if (f(mid) >= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
