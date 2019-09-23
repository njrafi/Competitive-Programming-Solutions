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
#define mxn 200005
/// Z array stores length of the longest substring starting from i which is also a prefix of S
int z[mxn];
char a[mxn], s[mxn];
void calc()
{
    mem(z, 0);
    int l = 0, r = 0;
    int len = strlen(s);
    Fre(i, 1, len)
    {
        if (i > r)
        {
            l = r = i;
            while (r < len && s[r] == s[r - l])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            if (z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else
            {
                l = i;
                while (r < len && s[r] == s[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}
/// number of occurence of b in a
int cnt[mxn];
int f()
{
    int len = strlen(a);
    strcpy(s, a);
    strcat(s, "$");
    strcat(s, a);
    ;
    int slen = strlen(s);
    calc();
    int ans = 0;
    Fre(i, len + 1, slen)
    {
        if (z[i])
        {
            cnt[1]++;
            cnt[z[i] + 1]--;
        }
        //                pfs(z[i]);
    }
    Fre(i, 1, mxn)
    {
        cnt[i] += cnt[i - 1];
        //                cout << i << " " << cnt[i] << endl;
    }
    vpi v;
    Fre(i, 1, len + 1)
    {
        if (z[slen - i] == i)
            v.pb(mp(i, cnt[i]));
    }
    pfn(v.sz);
    For(i, v.sz)
    {
        pfs(v[i].ff);
        pfn(v[i].ss);
    }
    //
    return ans;
}
int main()
{
    scanf("%s", a);
    f();
}
