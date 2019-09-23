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
struct point
{
    long long x, y; /// x*x or y*y should fit long long because of cross() function
    point() {}
    point(long long a, long long b)
    {
        x = a, y = b;
    }
    inline bool operator<(const point &p) const
    {
        return ((x < p.x) || (x == p.x && y < p.y));
    }
};
/// returns Euclidean distance between 2 points
double dist(point p1, point p2)
{
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
long long cross(const point &O, const point &A, const point &B)
{
    return ((A.x - O.x) * (B.y - O.y)) - ((A.y - O.y) * (B.x - O.x));
}
/// Polygon P convex or not, P is given in clock-wise of anti-clockwise order
bool isConvex(vector<point> P)
{
    int n = P.size();
    ///sort(P.begin(), P.end());
    if (n <= 2)
        return false;       /// Line or point is not convex
    n++, P.push_back(P[0]); /// Last point = first point
    bool flag = (cross(P[0], P[1], P[2]) > 0);
    for (int i = 1; (i + 1) < n; i++)
    {
        bool cmp = (cross(P[i], P[i + 1], (i + 2) == n ? P[1] : P[i + 2]) > 0);
        if (cmp ^ flag)
            return false;
    }
    return true;
}
/// Convex hull using the monotone chain algorithm
vector<point> convex_hull(vector<point> P)
{
    int i, t, k = 0, n = P.size();
    vector<point> H(n << 1);
    sort(P.begin(), P.end()); /// Can be converted to O(n) using radix sort
    for (i = 0; i < n; i++)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    for (i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    H.resize(k - 1); /// The last point is the same as the first in this implementation
                     //        H.pb(H[0]);
                     //        For(i,H.sz)
                     //                cout << H[i].x << " " << H[i].y << endl;
    return H;
}
/// vector
struct vec
{
    double x, y; // name: �vec� is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
/// convert 2 points to vector a->b
vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}
/// dot product of 2 vector
double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}
///  returns angle aob in rad
double angle(point a, point o, point b)
{
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
int main()
{
    int t, cs = 1, a, b, n;
    sf(t);
    while (t--)
    {
        vector<point> v;
        map<point, bool> m;
        sf(n);
        while (n--)
        {
            sff(a, b);
            if (m.find(point(a, b)) == m.end())
            {
                v.pb(point(a, b));
                m[point(a, b)] = 1;
            }
        }
        CASE(cs++);
        if (v.sz < 2)
        {
            puts("0");
            continue;
        }
        v = convex_hull(v);
        //
        //                For(i,v.sz)
        //                        cout << v[i].x << " " << v[i].y << endl;
        double ans = inf;
        For(i, v.sz)
        {
            double tem = angle(v[(i - 1 + v.sz) % v.sz], v[(i) % v.sz], v[(i + 1) % v.sz]);
            tem *= 180.0 / pi;
            ans = min(ans, tem);
            //                        cout << tem << endl;
        }
        printf("%.10f\n", ans);
    }
}
