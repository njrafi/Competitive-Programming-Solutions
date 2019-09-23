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
inline void fastRead(i64 *a)
{
    register char c = 0;
    while (c < 33)
        c = gc();
    *a = 0;
    while (c > 33)
    {
        *a = *a * 10 + c - '0';
        c = gc();
    }
}
inline void fastWrite(int a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc('\n');
}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
i64 multimod(i64 a, i64 b, i64 m)
{
    i64 ans = 0LL;
    a %= m, b %= m;
    while (b)
    {
        if (b & 1LL)
            ans = m - ans > a ? ans + a : ans + a - m;
        b >>= 1LL;
        a = (m - a) > a ? a + a : a + a - m;
    }
    return ans;
}
i64 bigmod(i64 b, i64 p, i64 m)
{
    i64 ret = 1LL;
    while (p)
    {
        if (p & 1LL)
            ret = multimod(ret, b, m);
        b = multimod(b, b, m);
        p >>= 1LL;
    }
    return ret;
}
bool isProbablePrime(i64 n, int k)
{
    if (n < 2)
        return false;
    if (n != 2 && n % 2 == 0)
        return false;
    if (n == 2)
        return true;
    i64 s = n - 1LL;
    while (s % 2 == 0)
        s >>= 1LL;
    while (k--)
    {
        i64 a = (rand() % (n - 1)) + 1;
        i64 tmp = s;
        i64 mod = bigmod(a, tmp, n);
        while (tmp != n - 1LL && mod != 1LL && mod != n - 1LL)
        {
            mod = multimod(mod, mod, n);
            tmp = tmp << 1LL;
        }
        if (mod != n - 1LL && tmp % 2LL == 0)
            return false;
    }
    return true;
}
#define mxn 1000006
bool ispr[mxn];
vi primes;
void sieve()
{
    int lim = sqrt(mxn);
    ispr[1] = 1;
    Fre(i, 2, lim) if (!ispr[i]) for (int j = i * i; j < mxn; j += i)
        ispr[j] = 1;
    Fre(i, 2, mxn) if (!ispr[i])
        primes.pb(i);
    //  For(i,10)
    //  cout << primes[i] << " ";
    //  cout << endl;
    //  cout << primes.sz * 4000 << endl;
}
vector<pair<i64, int>> factors(i64 n)
{
    vector<pair<i64, int>> v;
    for (int i = 0; i < primes.sz; i++)
    {
        if (primes[i] * primes[i] > n)
            break;
        if (n % primes[i] == 0)
        {
            v.pb(mp(primes[i], 0));
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                v.back().ss++;
            }
        }
    }
    if (n > 1)
        v.pb(mp(n, 1));
    return v;
}
vector<i64> tem;
vector<pair<i64, int>> dd;
i64 num;
void f(int pos)
{
    if (pos == dd.sz)
    {
        tem.pb(num);
        return;
    }
    i64 gun = 1;
    For(i, dd[pos].ss + 1)
    {
        num *= gun;
        f(pos + 1);
        num /= gun;
        gun *= dd[pos].ff;
    }
}
vector<i64> get_divisors(i64 n)
{
    dd = factors(n);
    tem.clr;
    num = 1;
    f(0);
    return tem;
}
int main()
{
    sieve();
    int t, cs = 1;
    i64 n, mn;
    sf(t);
    while (t--)
    {
        fastRead(&n);
        fastRead(&mn);
        CASE(cs++);
        if ((n < mxn && !ispr[n]) || isProbablePrime(n, 5))
        {
            if (mn == 1)
                puts("1");
            else
                puts("0");
            continue;
        }
        vector<i64> v = get_divisors(n);
        int ans = 0;
        For(i, v.sz) if (v[i] < n / v[i] && v[i] >= mn)
            ans++;
        fastWrite(ans);
    }
    return 0;
}
