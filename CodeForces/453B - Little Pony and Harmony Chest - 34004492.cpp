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
bool checkbit(int mask, int bit) { return mask & (1 << bit); }
int setbit(int mask, int bit) { return mask | (1 << bit); }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
vi prime;    /// below 60 prime list
vi divs[65]; /// x er prime div er list
int gg[100]; /// x koto number prime
void prime_gen()
{
    Fre(i, 2, 54)
    {
        bool ok = 1;
        Fre(j, 2, i) if (i % j == 0)
            ok = 0;
        if (ok)
            prime.pb(i);
    }
    mem(gg, -1);
    For(i, prime.sz)
        gg[prime[i]] = i;
    //        For(i,prime.sz)
    //                cout << prime[i] <<  " ";
    //        cout << endl;
    Fre(i, 2, 54)
    {
        int num = i;
        Fre(j, 2, num + 1) if (num % j == 0)
        {
            divs[i].pb(j);
            while (num % j == 0)
                num /= j;
        }
        //                cout << i << " ";
        //                For(k,divs[i].sz)
        //                        cout << divs[i][k] << " ";
        //                cout << endl;
    }
    //
    //        For(i,60)
    //                cout << i << " " << gg[i] << endl;
}
bool num_ok(int num, int mask)
{
    For(i, divs[num].sz) if (checkbit(mask, gg[divs[num][i]])) return 0;
    return 1;
}
vi v;
int dp[105][66000];
pii dir[105][66000];
int f(int pos, int mask)
{
    if (pos == v.sz)
        return 0;
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int ans = f(pos + 1, mask) + abs(v[pos] - 1);
    dir[pos][mask] = mp(1, mask);
    Fre(i, 2, 54) if (num_ok(i, mask))
    {
        int nmask = mask;
        For(j, divs[i].sz)
            nmask = setbit(nmask, gg[divs[i][j]]);
        int tem = f(pos + 1, nmask) + abs(v[pos] - i);
        if (tem < ans)
        {
            dir[pos][mask] = mp(i, nmask);
            ans = tem;
            //                                res[pos] = i;
        }
        //                        ans = min(ans, f(pos+1,nmask) + abs(v[pos] - i));
    }
    //        return ans;
    return dp[pos][mask] = ans;
}
void print(int pos, int mask)
{
    if (pos == v.sz)
        return;
    cout << dir[pos][mask].ff << " ";
    print(pos + 1, dir[pos][mask].ss);
}
int main()
{
    prime_gen();
    int n, inp;
    sf(n);
    while (n--)
    {
        sf(inp);
        v.pb(inp);
    }
    mem(dp, -1);
    f(0, 0);
    //        cout << f(0,0) << endl;
    print(0, 0);
    return 0;
}
