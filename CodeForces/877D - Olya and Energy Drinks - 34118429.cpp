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
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
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
struct info
{
    int dis, k, dir, x, y;
    info() {}
    info(int _dis, int _x, int _y, int _k, int _dir)
    {
        dis = _dis;
        x = _x;
        y = _y;
        k = _k;
        dir = _dir;
    }
};
class cmp
{
public:
    bool operator()(info a, info b)
    {
        return a.dis > b.dis; // top e choto ta thakbe
    }
};
vs v;
int n, m, k;
int dis[1005][1005][4];
bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || v[x][y] == '#')
        return 0;
    return 1;
}
void bfs(int x, int y)
{
    For(i, 1000)
        For(j, 1000)
            For(l, 4)
                dis[i][j][l] = inf;
    priority_queue<info, vector<info>, cmp> p;
    For(i, 4)
        dis[x][y][i] = 0;
    For(i, 4)
        p.push(info(0, x, y, k, i));
    while (!p.empty())
    {
        info u = p.top();
        p.pop();
        //                cout << u.x << " " << u.y << " " << u.dir << " " << u.dis << " " << u.k <<  endl;
        For(i, 4)
        {
            int xx = u.x + dx[i];
            int yy = u.y + dy[i];
            int newdis = u.dis;
            int newk = u.k + 1;
            if (u.dir != i || u.k == k)
            {
                newk = 1;
                newdis++;
            }
            //                        cout << "Vitre "  ;
            //                        cout << xx << " " << yy << " " << i << " " << newdis << " " << newk << endl;
            //                        cout << valid(xx,yy) << " " << dis[xx][yy] << endl;
            //                        cout << endl;
            if (valid(xx, yy) && dis[xx][yy][i] > newdis)
            {
                dis[xx][yy][i] = newdis;
                //                                dbg(12);
                //                               cout << xx+1 << " " << yy+1 << " " << newdis << " " << newk << endl;
                p.push(info(newdis, xx, yy, newk, i));
            }
        }
    }
}
int main()
{
    //        priority_queue< info , vector<info> ,cmp> p;
    //        p.push(info(10,0,0,0,0));
    //        p.push(info(12,0,0,0,0));
    //
    //        cout << p.top().dis;
    int x1, y1, x2, y2;
    string s;
    sfff(n, m, k);
    For(i, n)
    {
        cin >> s;
        v.pb(s);
    }
    sff(x1, y1);
    sff(x2, y2);
    bfs(x1 - 1, y1 - 1);
    if (dis[x2 - 1][y2 - 1][0] == inf && dis[x2 - 1][y2 - 1][1] == inf && dis[x2 - 1][y2 - 1][2] == inf && dis[x2 - 1][y2 - 1][3] == inf)
        puts("-1");
    else
    {
        int mn = inf;
        For(i, 4)
            mn = min(mn, dis[x2 - 1][y2 - 1][i]);
        pfn(mn);
    }
    return 0;
}