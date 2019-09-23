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
i64 gcd(i64 a, i64 b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
i64 bigmod(i64 num, i64 n)
{
    if (n == 0)
        return 1;
    i64 x = bigmod(num, n / 2);
    x = x * x % mod;
    if (n % 2 == 1)
        x = x * num % mod;
    return x;
}
i64 modinverse(i64 num)
{
    return bigmod(num, mod - 2) % mod;
}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define MAX 100005
struct Point
{
    long long x, y;
    Point()
    {
    }
    Point(long long xi, long long yi)
    {
        x = xi, y = yi;
    }
};
struct Segment
{
    struct Point P1, P2;
    Segment()
    {
    }
    Segment(struct Point P1i, struct Point P2i)
    {
        P1 = P1i, P2 = P2i;
    }
};
long long ccw(struct Point A, struct Point B, struct Point C)
{
    return ((B.x - A.x) * (C.y - A.y)) - ((C.x - A.x) * (B.y - A.y));
}
bool PointOnSeg(struct Segment S, struct Point P)
{
    long long x = P.x, y = P.y, x1 = S.P1.x, y1 = S.P1.y, x2 = S.P2.x, y2 = S.P2.y;
    long long a = x - x1, b = y - y1, c = x2 - x1, d = y2 - y1, dot = (a * c) + (b * d), len = (c * c) + (d * d);
    if (x1 == x2 && y1 == y2)
        return (x1 == x && y1 == y);
    if (dot < 0 || dot > len)
        return false;
    return ((((x1 * len) + (dot * c)) == (x * len)) && (((y1 * len) + (dot * d)) == (y * len)));
}
struct Polygon
{
#define CLOCKWISE 11230926
#define ANTICLOCK 37281927
    int n;
    struct Point ar[MAX];
    Polygon()
    {
    }
    Polygon(int ni, struct Point *T, int flag)
    {
        n = ni;
        for (int i = 0; i < n; i++)
        {
            if (flag == CLOCKWISE)
                ar[i] = T[i];
            else
                ar[i] = T[n - i - 1];
        }
    }
    bool contains(struct Point P, bool strictly)
    {
        int mid, low = 1, high = n - 1, idx = 1;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (ccw(ar[0], P, ar[mid]) > 0)
                low = mid + 1;
            else
                idx = mid, high = mid - 1;
        }
        if (!strictly && PointOnSeg(Segment(ar[0], ar[n - 1]), P))
            return true;
        if (!strictly && PointOnSeg(Segment(ar[idx], ar[idx - 1]), P))
            return true;
        if (idx == 1 || ccw(ar[0], P, ar[n - 1]) == 0)
            return false;
        return (ccw(ar[idx], P, ar[idx - 1]) < 0);
    }
};
bool ok(vpi v, vpi w)
{
    Polygon p;
    p.n = v.sz;
    For(i, v.sz)
    {
        p.ar[i].x = v[i].ff;
        p.ar[i].y = v[i].ss;
    }
    For(i, w.sz) if (!p.contains(Point(w[i].ff, w[i].ss), 1)) return 0;
    return 1;
}
int main()
{
    vpi v, w;
    int a, b, n, m;
    sff(n, m);
    For(i, n)
    {
        sff(a, b);
        v.pb(mp(a, b));
    }
    For(i, m)
    {
        sff(a, b);
        w.pb(mp(a, b));
    }
    //    cout << ok(v,w) << endl;
    //    cout << ok(w,v) << endl;
    if (ok(v, w) || ok(w, v))
    {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}