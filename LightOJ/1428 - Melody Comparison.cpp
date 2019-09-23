#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
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
vi v;
/// pattern string
int ssz;
namespace suff
{
/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/
const int MAXN = 1 << 16;
const int MAXL = 16;
int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], ranky[MAXL][MAXN];
char str[MAXN];
//char str2[MAXN];
inline bool equal(const int &u, const int &v)
{
    if (!stp)
        return str[u] == str[v];
    if (ranky[stp - 1][u] != ranky[stp - 1][v])
        return false;
    int a = u + mv < n ? ranky[stp - 1][u + mv] : -1;
    int b = v + mv < n ? ranky[stp - 1][v + mv] : -1;
    return a == b;
}
void update()
{
    int i, rnk;
    for (i = 0; i < n; i++)
        sum[i] = 0;
    for (i = rnk = 0; i < n; i++)
    {
        suffix[i] = tmp[i];
        if (i && !equal(suffix[i], suffix[i - 1]))
        {
            ranky[stp][suffix[i]] = ++rnk;
            sum[rnk + 1] = sum[rnk];
        }
        else
            ranky[stp][suffix[i]] = rnk;
        sum[rnk + 1]++;
    }
}
void Sort()
{
    int i;
    for (i = 0; i < n; i++)
        cnt[i] = 0;
    //memset(tmp, -1, sizeof tmp);
    for (i = 0; i < mv; i++)
    {
        int idx = ranky[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for (i = 0; i < n; i++)
    {
        int idx = suffix[i] - mv;
        if (idx < 0)
            continue;
        idx = ranky[stp - 1][idx];
        int x = sum[idx];
        tmp[x + cnt[idx]] = suffix[i] - mv;
        cnt[idx]++;
    }
    update();
    return;
}
inline bool cmp(const int &a, const int &b)
{
    if (str[a] != str[b])
        return str[a] < str[b];
    return false;
}
void SortSuffix()
{
    int i;
    for (i = 0; i < n; i++)
        tmp[i] = i;
    sort(tmp, tmp + n, cmp);
    stp = 0;
    update();
    ++stp;
    for (mv = 1; mv < n; mv <<= 1)
    {
        Sort();
        stp++;
    }
    stp--;
    for (i = 0; i <= stp; i++)
        ranky[i][n] = -1;
}
/// return lcp of uth suffix and vth suffix of main string
inline int lcp(int u, int v)
{
    if (u == v)
        return n - u;
    int ret, i;
    for (ret = 0, i = stp; i >= 0; i--)
    {
        if (ranky[i][u] == ranky[i][v])
        {
            ret += 1 << i;
            u += 1 << i;
            v += 1 << i;
        }
    }
    return ret;
}
/// Distinct substring
i64 disSub()
{
    i64 ans = 0;
    For(i, n)
    {
        int l = 1;
        if (i)
            l = lcp(suffix[i], suffix[i - 1]) + 1;
        int r = n - suffix[i];
        vi::iterator it = lower_bound(all(v), suffix[i]);
        int sidx = n;
        if (it != v.end())
            sidx = min(sidx, *it + ssz);
        sidx = sidx - suffix[i];
        //                cout << "info: " << *it << " " << *it + ssz << endl;
        //                cout << l << " " << r << " " << sidx << endl;
        //                cout << endl;
        ans += max(0, sidx - l + 1);
    }
    return ans;
}
void printSuffix()
{
    printf("INIT %s\n", str);
    for (int i = 0; i < n; i++)
    {
        printf("%3d %3d : ", i, suffix[i]);
        for (int j = suffix[i]; j < n; j++)
            cout << str[j];
        if (i + 1 < n)
            printf("    %d", lcp(suffix[i], suffix[i + 1]));
        cout << endl;
    }
}
} // namespace suff
#define ui64 unsigned long long
namespace hashString
{
/// prime
const int p1 = 163;
/// total string
const int totst = 1;
/// Max String Length
const int mxns = 50004;
ui64 pr1[mxns];
vector<ui64> h1[totst];
/// Remember to call in first
void gen_prime()
{
    pr1[0] = 1;
    Fre(i, 1, mxns)
        pr1[i] = pr1[i - 1] * p1;
}
/// generating hash
void gen(string sss, int idx = 0)
{
    h1[idx].clr;
    h1[idx].pb(0);
    For(i, sss.sz)
        h1[idx]
            .pb((h1[idx][i] * p1) + sss[i]);
}
/// 0 based indexing
/// gives hash of a range
ui64 hashOfRange(int l, int r, int idx = 0)
{
    int len = r - l + 1;
    ui64 hash1 = h1[idx][r + 1] - (h1[idx][l] * pr1[len]);
    return hash1;
}
} // namespace hashString
string s;
char ss[50004];
void calc_hash()
{
    v.clr;
    scanf("%s", ss);
    s = ss;
    ssz = s.sz - 1;
    hashString::gen(s);
    ui64 hh = hashString::hashOfRange(0, ssz);
    s = suff::str;
    hashString::gen(s);
    For(i, s.sz)
    {
        int r = i + ssz;
        if (r >= s.sz)
            break;
        if (hashString::hashOfRange(i, r) == hh)
            v.pb(i);
    }
    //
    //        For(i,v.sz)
    //                cout << v[i] << " ";
    //
    //        cout << endl;
}
int main()
{
    //        READ;
    //        WRITE;
    hashString::gen_prime();
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        scanf("%s", suff::str);
        suff::n = strlen(suff::str);
        calc_hash();
        suff::SortSuffix();
        //      suff::printSuffix();
        CASE(cs++);
        printf("%lld\n", suff::disSub());
        //      cout << suff::disSub() << endl;
    }
}
