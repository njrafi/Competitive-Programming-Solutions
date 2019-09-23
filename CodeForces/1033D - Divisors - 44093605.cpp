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
#define mod 998244353
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
i64 gcd(i64 a, i64 b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
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
#define ui64 unsigned long long int
pair<bool, ui64> isSquare(ui64 n, int gg)
{
    ui64 mxn = 1e18;
    mxn *= 3;
    ui64 lo = 1, hi = pow(mxn, 1.0 / gg), ans = 0;
    while (lo <= hi)
    {
        ui64 mid = (lo + hi) / 2;
        ui64 val = 1;
        For(i, gg)
            val *= mid;
        if (val <= n)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    ui64 val = 1;
    For(i, gg)
        val *= ans;
    return {(val == n), ans};
}
int main()
{
    //        ui64 n;
    //        while(cin >> n)
    //        {
    //                Fre(i,2,5)
    //                {
    //                        cout << i << " " << isSquare(n,i).ff << endl;
    //                }
    //        }
    map<ui64, int> factCnt;
    map<ui64, int> primePairCnt;
    vector<ui64> pending;
    int t;
    ui64 n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (isSquare(n, 4).ff)
        {
            //                        cout << "4" << endl;
            factCnt[isSquare(n, 4).ss] += 4;
        }
        else if (isSquare(n, 3).ff)
        {
            //                        cout << "3" << endl;
            factCnt[isSquare(n, 3).ss] += 3;
        }
        else if (isSquare(n, 2).ff)
        {
            //                        cout << 2 << endl;
            //                        cout << isSquare(n,2).ss << endl;
            factCnt[isSquare(n, 2).ss] += 2;
        }
        else
        {
            pending.pb(n);
        }
    }
    For(i, pending.sz)
        For(j, pending.sz) if (pending[i] != pending[j])
    {
        ui64 gg = gcd(pending[i], pending[j]);
        if (gg > 1)
        {
            factCnt[gg]++;
            factCnt[gg]--;
        }
    }
    For(j, pending.sz)
    {
        n = pending[j];
        bool ok = 0;
        foreach (i, factCnt)
        {
            if (n % (i->ff) == 0)
            {
                ok = 1;
                //                                cout << pending[j] << endl;
                factCnt[i->ff]++;
                factCnt[n / (i->ff)]++;
                break;
            }
        }
        if (!ok)
            primePairCnt[n]++;
    }
    i64 ans = 1;
    foreach (i, factCnt)
    {
        ans *= (i->ss + 1);
        ans %= mod;
    }
    foreach (i, primePairCnt)
    {
        ans *= (i->ss + 1);
        ans %= mod;
        ans *= (i->ss + 1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
