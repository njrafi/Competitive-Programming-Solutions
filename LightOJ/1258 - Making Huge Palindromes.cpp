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
#define inf 536870911
#define infll 12345678901234567
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
//int setbit(int mask,int bit){return mask  (1<<bit);}
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mod1 1000000007
#define p1 43
int len;
int h1[1000006], h2[1000006], pr1[1000006];
char s[1000006];
int f(int r1, int l2, int r2)
{
    int siz = r2 - l2;
    int l1 = r1 - siz;
    l2 = len - 1 - l2;
    r2 = len - 1 - r2;
    swap(l2, r2);
    if (l1 < 0 || l1 >= len)
        return inf;
    i64 hash1 = ((i64)h1[r1 + 1] - ((i64)h1[l1] * pr1[r1 - l1 + 1]) % mod1 + mod1) % mod1;
    i64 hash3 = ((i64)h2[r2 + 1] - ((i64)h2[l2] * pr1[r2 - l2 + 1]) % mod1 + mod1) % mod1;
    /*  cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        string s1,s2;
        Fre(i,l1,r1 + 1)
                s1 += s[i];
        Fre(i,l2,r2 + 1)
                s2 += rs[i];
        cout << s1 << " " << hash1 << endl;
       cout << s2 << " " << hash3 << endl;
        cout << endl;
        */
    if (hash1 == hash3)
        return l1;
    return inf;
}
int main()
{
    pr1[0] = 1;
    For(i, 1000006)
        pr1[i + 1] = (((i64)pr1[i] * p1) % mod1);
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        scanf("%s", s);
        len = strlen(s);
        For(i, len)
        {
            h1[i + 1] = ((((i64)h1[i] * p1) + s[i]) % mod1);
            h2[i + 1] = ((((i64)h2[i] * p1) + s[len - 1 - i]) % mod1);
        }
        int ans = inf;
        Fre(i, max(len / 2 - 3, 0), len)
        {
            ans = min(ans, f(i, i, len - 1));
            ans = min(ans, f(i, i + 1, len - 1));
            if (ans < inf)
                break;
        }
        CASE(cs++);
        pfn(ans + len);
    }
    return 0;
}
