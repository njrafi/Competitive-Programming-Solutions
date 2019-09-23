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
bool isboring(string s, int ssz)
{
    For(i, s.sz)
        Fre(j, i, s.sz)
    {
        string gg;
        Fre(k, i, j + 1)
            gg += s[k];
        string ggr = gg;
        reverse(all(ggr));
        if (gg == ggr && gg.sz >= ssz)
            return 1;
    }
    return 0;
}
int brute_check(string s, int szz)
{
    int ans = 0;
    For(i, s.sz)
        Fre(j, i, s.sz)
    {
        string gg;
        Fre(k, i, j + 1)
            gg += s[k];
        ans += isboring(gg, szz);
        //                        if(isboring(gg,szz))
        //                                cout << gg << endl;
    }
    return ans;
}
#define ui64 unsigned long long
namespace hashString
{
const int p1 = 163;
const int totst = 3;
const int mxns = 100005;
ui64 pr1[mxns];
vector<ui64> h1[totst];
void gen_prime()
{
    pr1[0] = 1;
    Fre(i, 1, mxns)
        pr1[i] = pr1[i - 1] * p1;
}
void gen(string sss, int idx = 0)
{
    h1[idx].clr;
    h1[idx].pb(0);
    For(i, sss.sz)
        h1[idx]
            .pb((h1[idx][i] * p1) + sss[i]);
}
ui64 hashOfRange(int l, int r, int idx = 0)
{
    int len = r - l + 1;
    ui64 hash1 = h1[idx][r + 1] - (h1[idx][l] * pr1[len]);
    return hash1;
}
} // namespace hashString
bool ispalin(int n, int l, int r)
{
    int rr = n - 1 - l;
    int ll = n - 1 - r;
    if (hashString::hashOfRange(l, r, 0) == hashString::hashOfRange(ll, rr, 1))
        return 1;
    return 0;
}
i64 f(string s, int k)
{
    hashString::gen_prime();
    hashString::gen(s, 0);
    reverse(all(s));
    hashString::gen(s, 1);
    //        reverse(all(s));
    int last = -1;
    i64 ans = 0;
    For(i, s.sz)
    {
        if (i + k - 1 == s.sz)
            break;
        if (ispalin(s.sz, i, i + k - 1))
        {
            i64 ll = i - last;
            i64 rr = s.sz - i - k + 1;
            ans += ll * rr;
            last = i;
        }
        else if (i + k != s.sz && ispalin(s.sz, i, i + k))
        {
            i64 ll = i - last;
            i64 rr = s.sz - i - k;
            ans += ll * rr;
            last = i;
        }
    }
    return ans;
}
char ss[100005];
int main()
{
    //        string s;
    //        int k;
    //        while(cin >> k >> s )
    //        {
    //
    //                cout << f(s,k) << endl;
    //                cout << brute_check(s,k) << endl;
    //                cout << s.sz * (s.sz+1) / 2  - brute_check(s,k) << endl;
    //                cout << s.sz * (s.sz+1) / 2  - f(s,k) << endl;
    //        }
    string s;
    int t, k;
    sf(t);
    while (t--)
    {
        sf(k);
        scanf("%s", ss);
        s = ss;
        //                cout << s.sz * (s.sz+1) / 2  - f(s,k) << endl;
        printf("%lld\n", (i64)s.sz * (s.sz + 1) / 2 - f(s, k));
    }
    return 0;
}
