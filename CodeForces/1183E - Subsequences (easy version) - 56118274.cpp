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
/// source: https://www.geeksforgeeks.org/count-unique-subsequences-of-length-k/
string v;
//vi v;
i64 f(int k)
{
    if (v.sz < k || v.sz < 1 || k < 1)
        return 0;
    if (v.sz == k)
        return 1;
    vector<i64> v1, v2, v3;
    For(i, v.sz)
    {
        v1.pb(0);
        v2.pb(0);
    }
    For(i, 300)
        v3.pb(0);
    v2[v.sz - 1] = 1;
    v3[v[v.sz - 1] - 1] = 1;
    for (int i = v.sz - 2; i >= 0; i--)
    {
        v2[i] = v2[i + 1];
        if (v3[v[i] - 1] == 0)
        {
            v2[i]++;
            v3[v[i] - 1] = 1;
        }
    }
    // iterate for all possible values of K
    for (int j = 1; j < k; j++)
    {
        fill(v3.begin(), v3.end(), 0);
        v1[v.sz - 1] = 0;
        for (int i = v.sz - 2; i >= 0; i--)
        {
            v1[i] = v1[i + 1];
            v1[i] = v1[i] + v2[i + 1];
            v1[i] = v1[i] - v3[v[i] - 1];
            v3[v[i] - 1] = v2[i + 1];
        }
        v2 = v1;
    }
    return v1[0];
}
int main()
{
    i64 n, k;
    cin >> n >> k;
    cin >> v;
    i64 ans = 0;
    for (int i = v.sz; i > 1; i--)
    {
        i64 total = f(i);
        if (total >= k)
        {
            ans += k * (v.sz - i);
            cout << ans << endl;
            return 0;
        }
        else
            ans += total * (v.sz - i);
        k -= total;
    }
    si s;
    For(i, v.sz)
        s.insert(v[i]);
    i64 total = s.sz;
    if (total >= k)
    {
        ans += k * (v.sz - 1);
        cout << ans << endl;
        return 0;
    }
    else
        ans += total * (v.sz - 1);
    k -= total;
    total = 1;
    if (total >= k)
    {
        ans += k * v.sz;
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
