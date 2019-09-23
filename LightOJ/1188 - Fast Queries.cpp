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
#define CASE(a) printf("Case %d:\n", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
inline void fastRead(int *a)
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
//int setbit(int mask,int bit){return mask  (1<<bit);}
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
struct range
{
    int l, r, ind;
};
vector<range> qr;
range tem;
vi v;
int bl, cnt, freq[100005], ans[50005];
bool f1(range a, range b)
{
    if (a.l / bl == b.l / bl)
        return a.r < b.r;
    return a.l / bl < b.l / bl;
}
void add(int ind, int i, int en)
{
    do
    {
        ind += i;
        freq[v[ind]]++;
        if (freq[v[ind]] == 1)
            cnt++;
    } while (ind != en);
}
void rem(int ind, int i, int en)
{
    while (ind != en)
    {
        freq[v[ind]]--;
        if (!freq[v[ind]])
            cnt--;
        ind += i;
    }
}
int main()
{
    int t, inp, n, q, cs = 1, l, r;
    fastRead(&t);
    while (t--)
    {
        v.clr;
        qr.clr;
        cnt = 0;
        mem(freq, 0);
        fastRead(&n);
        fastRead(&q);
        bl = sqrt(n) + 1;
        For(i, n)
        {
            fastRead(&inp);
            v.pb(inp);
        }
        For(i, q)
        {
            fastRead(&l);
            fastRead(&r);
            tem.l = l - 1;
            tem.r = r - 1;
            tem.ind = i;
            qr.pb(tem);
        }
        sort(all(qr), f1);
        int st = qr[0].l, en = qr[0].l - 1;
        For(i, qr.sz)
        {
            l = qr[i].l;
            r = qr[i].r;
            if (l < st)
                add(st, -1, l);
            else if (l > st)
                rem(st, 1, l);
            if (r < en)
                rem(en, -1, r);
            else if (r > en)
                add(en, 1, r);
            ans[qr[i].ind] = cnt;
            st = l;
            en = r;
        }
        CASE(cs++);
        For(i, q)
            fastWrite(ans[i]);
    }
    return 0;
}