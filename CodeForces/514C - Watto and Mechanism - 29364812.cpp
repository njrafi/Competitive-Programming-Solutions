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
#define mod1 1000000007
#define mod2 1000000009
#define p1 47
#define p2 101
#define mxn 1000005
i64 pr1[mxn], pr2[mxn];
i64 h1[mxn], h2[mxn];
char s[mxn];
int ssz;
map<pair<i64, i64>, bool> m;
void prime_calc()
{
    pr1[0] = 1;
    pr2[0] = 1;
    Fre(i, 1, mxn)
    {
        pr1[i] = (pr1[i - 1] * p1) % mod1;
        pr2[i] = (pr2[i - 1] * p2) % mod2;
    }
}
void hash_calc()
{
    h1[0] = 0;
    h2[0] = 0;
    For(i, ssz)
    {
        h1[i + 1] = (h1[i] * p1 + s[i]) % mod1;
        h2[i + 1] = (h2[i] * p2 + s[i]) % mod2;
    }
}
pair<i64, i64> hash_lr(int l, int r)
{
    if (l > r)
        return mp(0, 0);
    int len = r - l + 1;
    i64 hash1 = (h1[r + 1] - (h1[l] * pr1[len]) % mod1 + mod1) % mod1;
    i64 hash2 = (h2[r + 1] - (h2[l] * pr2[len]) % mod2 + mod2) % mod2;
    return mp(hash1, hash2);
}
int main()
{
    prime_calc();
    int n, q;
    sff(n, q);
    while (n--)
    {
        scanf("%s", s);
        ssz = strlen(s);
        hash_calc();
        m[hash_lr(0, ssz - 1)] = 1;
    }
    while (q--)
    {
        scanf("%s", s);
        ssz = strlen(s);
        hash_calc();
        bool ok = 0;
        For(i, ssz)
        {
            For(j, 3)
            {
                i64 ch = j + 'a';
                if (ch == s[i])
                    continue;
                pair<i64, i64> LL = hash_lr(0, i - 1);
                pair<i64, i64> RR = hash_lr(i + 1, ssz - 1);
                i64 hash1 = (LL.ff * pr1[ssz - i] + ch * pr1[ssz - 1 - i] + RR.ff) % mod1;
                i64 hash2 = (LL.ss * pr2[ssz - i] + ch * pr2[ssz - 1 - i] + RR.ss) % mod2;
                if (m.find(mp(hash1, hash2)) != m.end())
                {
                    puts("YES");
                    ok = 1;
                    break;
                }
            }
            if (ok)
                break;
        }
        if (!ok)
            puts("NO");
    }
    return 0;
}