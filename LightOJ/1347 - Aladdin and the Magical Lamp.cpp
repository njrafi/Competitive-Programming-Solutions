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
namespace suff
{
/// Read detains in evernote
/// A better algo for array construction is skew/dc3 (available in Zahin vai notebook)
///remember to change mxn
const int mxn = 3 * 5005;
struct info
{
    int prvR, newR, idx; // prev rank,new rank,and index
    info()
    {
        prvR = newR = idx = 0;
    }
};
bool cmp(info a, info b) // sorting according to rank
{
    if (a.prvR == b.prvR)
        return a.newR < b.newR;
    return a.prvR < b.prvR;
}
info arr[mxn];     // information array
                   /// after building arr[i].idx is the i'th value of suffix array
int Rank[18][mxn]; // will contain the rank
int n;             // text size
string text;       // The Text
int lcp[mxn];      // lcp array
                   /// Suffix Array is an array which will contains the index of suffix of a string if the suffixes were lexicographical sorted
                   /// complexity (n * log(n) ^ 2)
void build_suffix_array(string s)
{
    text = s;
    text += '$';
    n = text.sz;
    mem(Rank, 0);
    For(i, n)
    {
        arr[i] = info();
        Rank[0][i] = text[i]; // rank suffix according to first char
    }
    for (int step = 1, jump = 1; jump < n; step++, jump *= 2)
    {
        For(i, n)
        {
            arr[i].idx = i;
            arr[i].prvR = Rank[step - 1][i];
            arr[i].newR = -1;
            if (i + jump < n)
                arr[i].newR = Rank[step - 1][i + jump];
        }
        sort(arr, arr + n, cmp);
        Rank[step][arr[0].idx] = 0;
        Fre(i, 1, n) if (arr[i].prvR == arr[i - 1].prvR && arr[i].newR == arr[i - 1].newR)
            Rank[step][arr[i].idx] = Rank[step][arr[i - 1].idx];
        else Rank[step][arr[i].idx] = i;
    }
}
///The LCP Array is the array of Longest Common Prefixes between the ith suffix and the (i-1)th suffix in the Suffix Array
///complexity (n * log(n))
void build_LCP_array()
{
    lcp[0] = 0;
    Fre(i, 1, n)
    {
        int id1 = arr[i - 1].idx;
        int id2 = arr[i].idx;
        lcp[i] = 0;
        for (int j = ceil(log2(n)); j >= 0; j--)
            if (Rank[j][id1] == Rank[j][id2] && Rank[j][id2])
            {
                lcp[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
    }
}
void print_array()
{
    cout << "\n\nSuffix Array : \n\n";
    For(i, n)
            cout
        << i << " " << arr[i].idx << " " << text.substr(arr[i].idx) << endl;
    cout << "\n\nLCP Array: \n\n";
    Fre(i, 1, n)
            cout
        << i << ' ' << lcp[i] << endl;
}
int whichString(int sz1, int sz2, int sz3, int idx)
{
    if (arr[idx].idx < sz1)
        return 1;
    else if (arr[idx].idx < sz1 + sz2)
        return 2;
    else
        return 3;
}
int get_res(int sz1, int sz2, int sz3)
{
    int res = 0;
    //                cout << "in get_res : " << endl;
    Fre(i, 3, text.sz)
    {
        si aSet;
        aSet.insert(whichString(sz1, sz2, sz3, i - 2));
        aSet.insert(whichString(sz1, sz2, sz3, i - 1));
        aSet.insert(whichString(sz1, sz2, sz3, i));
        //                        cout << i << " " << aSet.sz << " " << lcp[i-1] << " " << lcp[i] << endl;
        if (aSet.sz == 3)
            res = max(res, min(lcp[i - 1], lcp[i]));
    }
    return res;
}
} // namespace suff
int main()
{
    int t, cs = 1;
    sf(t);
    string s1, s2, s3;
    char sss[5005];
    while (t--)
    {
        scanf("%s", sss);
        s1 = sss;
        scanf("%s", sss);
        s2 = sss;
        scanf("%s", sss);
        s3 = sss;
        suff::build_suffix_array(s1 + s2 + s3);
        suff::build_LCP_array();
        //                suff::print_array();
        CASE(cs++);
        pfn(suff::get_res(s1.sz, s2.sz, s3.sz));
    }
    return 0;
}
