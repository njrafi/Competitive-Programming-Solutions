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
#define ui64 unsigned long long
/// very little chance of clash
/// if clash do double hash
namespace hashString
{
const int p1 = 163;
/// the prime
const int mxns = 200005; // string size
const int totst = 55;    // total string for hash
                         /// change it properly
ui64 pr1[totst][mxns];
ui64 h1[totst][mxns];
string s[totst];
/// generate hash
void gen(string sss, int idx = 0)
{
    s[idx] = sss;
    pr1[idx][0] = 1;
    Fre(i, 1, s[idx].sz + 4)
        pr1[idx][i] = pr1[idx][i - 1] * p1;
    For(i, s[idx].sz)
        h1[idx][i + 1] = (h1[idx][i] * p1) + s[idx][i];
    //
}
/// 0 based indexing
/// gives hash of a range
ui64 hashOfRange(int l, int r, int idx = 0)
{
    int len = r - l + 1;
    ui64 hash1 = h1[idx][r + 1] - (h1[idx][l] * pr1[idx][len]);
    //
    return hash1;
}
} // namespace hashString
bool match(vector<ui64> v, vector<ui64> w)
{
    si s;
    For(i, 26)
        s.insert(i);
    For(i, v.sz)
        For(j, w.sz) if (v[i] == w[j])
    {
        if (s.find(i) == s.end() || s.find(j) == s.end())
            continue;
        if (v[j] != w[i])
            continue;
        //                                cout << (char)(i+'a') << " " << (char)(j + 'a') << endl;
        s.erase(i);
        s.erase(j);
    }
    return (!s.sz);
}
int main()
{
    //        hashString::gen("gglala");
    //        cout << hashString::hashOfRange(0,5) << endl;
    int n, m;
    vector<ui64> v;
    sff(n, m);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 26; i++)
    {
        int let = i + 'a';
        string tem;
        // string 1 processing
        For(j, s1.sz) if (s1[j] == let)
            tem += '1';
        else tem += '0';
        hashString::gen(tem, i);
        tem.clr;
        // string 2 processing
        For(j, s2.sz) if (s2[j] == let)
            tem += '1';
        else tem += '0';
        hashString::gen(tem, i + 26);
        v.pb(hashString::hashOfRange(0, s2.sz - 1, i + 26));
    }
    //        For(i,v.sz)
    //                cout << v[i] << endl;
    //        sort(all(v));
    vi ans;
    For(i, s1.sz)
    {
        int r = s2.sz - 1 + i;
        if (r >= s1.sz)
            break;
        vector<ui64> w;
        For(j, 26)
            w.pb(hashString::hashOfRange(i, r, j));
        //                cout << i << endl;
        if (match(v, w))
            ans.pb(i + 1);
        //                cout << endl;
    }
    pfn(ans.sz);
    For(i, ans.sz)
        pfs(ans[i]);
    //        cout << endl;
    return 0;
}
