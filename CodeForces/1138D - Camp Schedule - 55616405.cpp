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
#define mxn 500005
int cnt[2], need[2];
char s[mxn];
int z[mxn];
int calc()
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
    int lenNow = len - 1;
    Fre(i, 1, len) if (z[i] == lenNow) return lenNow;
    else lenNow--;
    return 0;
}
int main()
{
    scanf("%s", s);
    int slen = strlen(s);
    For(i, slen)
        cnt[s[i] - '0']++;
    scanf("%s", s);
    slen = strlen(s);
    For(i, slen)
        need[s[i] - '0']++;
    calc();
    string w = s;
    string ans;
    if (cnt[0] >= need[0] && cnt[1] >= need[1])
    {
        cnt[0] -= need[0];
        cnt[1] -= need[1];
        ans += w;
    }
    w.clr;
    int overlap = calc();
    //        cerr << overlap << endl;
    mem(need, 0);
    Fre(i, overlap, slen)
    {
        w += s[i];
        need[s[i] - '0']++;
    }
    //        cout << w << endl;
    while (1)
    {
        if (cnt[0] >= need[0] && cnt[1] >= need[1])
        {
            cnt[0] -= need[0];
            cnt[1] -= need[1];
            ans += w;
        }
        else
            break;
    }
    For(i, cnt[0]) ans += '0';
    For(i, cnt[1]) ans += '1';
    cout << ans << endl;
    return 0;
}
