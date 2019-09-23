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
#define CASE(a) printf("Case %d:\n", a)
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
    /// change to int/long long if needed
    double x, y;
    /// default Constructor
    point()
    {
        x = y = 0.0;
    }
    point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    /// sort by x co-ordinate then y co-ordinate
    bool operator<(point other) const
    {
        if (abs(x - other.x) > eps)
            return x < other.x;
        return y < other.y;
    }
    /// to check if two points are equal
    bool operator==(point other) const
    {
        return ((abs(x - other.x) < eps) && (abs(y - other.y) < eps));
    }
};
/// returns Euclidean distance between 2 points
double dist(point p1, point p2)
{
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
struct line
{
    double a, b, c;
    line() {}
    line(double aa, double bb, double cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
};
/// given two point p1 and p2 output the line equation
line pointsToLine(point p1, point p2)
{
    line l;
    if (abs(p1.x - p2.x) < eps) // vertical line is fine
    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x; // default values
    }
    else
    {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}
/// returns if point p is on line l
bool pointOnLine(point p, line l)
{
    double tot = l.a * p.x + l.b * p.y + l.c;
    if (abs(tot) < eps)
        return 1;
    return 0;
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
/// returns cross product of 2 vectors
double cross(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}
/// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) > 0;
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
/// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P, bool strictly)
{
    if ((int)P.size() == 0)
        return false;
    double sum = 0; // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size() - 1; i++)
    {
        if (!strictly)
        {
            line l = pointsToLine(P[i], P[i + 1]);
            if (pointOnLine(pt, l) && abs(dist(pt, P[i]) + dist(pt, P[i + 1]) - dist(P[i], P[i + 1])) < eps)
                return 1;
        }
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]); // left turn/ccw
        else
            sum -= angle(P[i], pt, P[i + 1]);
    } // right turn/cw
    return abs(abs(sum) - 2.0 * pi) < eps;
}
int main()
{
    //WRITE;
    int t, cs = 1, a, b, q, n;
    sf(t);
    while (t--)
    {
        vector<point> v;
        sf(n);
        while (n--)
        {
            sff(a, b);
            v.pb(point(a, b));
        }
        v.pb(v[0]);
        CASE(cs++);
        sf(q);
        while (q--)
        {
            sff(a, b);
            if (inPolygon(point(a, b), v, 0))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
