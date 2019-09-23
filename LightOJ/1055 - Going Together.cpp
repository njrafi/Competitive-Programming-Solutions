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
vs v;
bool obs[12][12];
bool target[12][12];
vpi st;
int dis[12][12][12][12][12][12];
int n;
struct info
{
    int x1, y1, x2, y2, x3, y3;
    info()
    {
        x1 = x2 = x3 = y1 = y2 = y3 = 0;
    }
    info(int xx1, int yy1, int xx2, int yy2, int xx3, int yy3)
    {
        x1 = xx1;
        y1 = yy1;
        x2 = xx2;
        y2 = yy2;
        x3 = xx3;
        y3 = yy3;
    }
};
bool ok(info ii)
{
    if (target[ii.x1][ii.y1] && target[ii.x2][ii.y2] && target[ii.x3][ii.y3] && mp(ii.x1, ii.y1) != mp(ii.x2, ii.y2) && mp(ii.x1, ii.y1) != mp(ii.x3, ii.y3) && mp(ii.x3, ii.y3) != mp(ii.x2, ii.y2))
        return 1;
    return 0;
}
bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || obs[x][y])
    {
        //                cout << "hamba" << endl;
        //                cout << obs[x][y] << endl;
        //                cout << x << " " << y << endl;
        return 0;
    }
    return 1;
}
void bfs()
{
    int ans = inf;
    mem(dis, -1);
    queue<info> q;
    q.push(info(st[0].ff, st[0].ss, st[1].ff, st[1].ss, st[2].ff, st[2].ss));
    dis[st[0].ff][st[0].ss][st[1].ff][st[1].ss][st[2].ff][st[2].ss] = 0;
    while (!q.empty())
    {
        info ii = q.front();
        q.pop();
        if (ok(ii))
        {
            ans = min(ans, dis[ii.x1][ii.y1][ii.x2][ii.y2][ii.x3][ii.y3]);
            continue;
        }
        //                cout << ii.x1 << " " << ii.y1 << " " << ii.x2 << " " << ii.y2 << " " << ii.x3 << " " << ii.y3 << endl;
        For(i, 4)
        {
            int gg1 = 0, gg2 = 0, gg3 = 0, x1, x2, x3, y1, y2, y3;
            x1 = ii.x1 + dx[i];
            y1 = ii.y1 + dy[i];
            //                        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            if (valid(x1, y1))
                gg1++;
            else
            {
                x1 = ii.x1;
                y1 = ii.y1;
            }
            //                        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            x2 = ii.x2 + dx[i];
            y2 = ii.y2 + dy[i];
            if (valid(x2, y2))
                gg2++;
            else
            {
                x2 = ii.x2;
                y2 = ii.y2;
            }
            //                        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            x3 = ii.x3 + dx[i];
            y3 = ii.y3 + dy[i];
            if (valid(x3, y3))
                gg3++;
            else
            {
                x3 = ii.x3;
                y3 = ii.y3;
            }
            if (gg1 && mp(x1, y1) == mp(x2, y2) || mp(x1, y1) == mp(x3, y3))
            {
                gg1 = 0;
                x1 = ii.x1;
                y1 = ii.y1;
            }
            if (gg2 && mp(x2, y2) == mp(x1, y1) || mp(x2, y2) == mp(x3, y3))
            {
                gg2 = 0;
                x2 = ii.x2;
                y2 = ii.y2;
            }
            if (gg2 && mp(x3, y3) == mp(x1, y1) || mp(x2, y2) == mp(x3, y3))
            {
                gg3 = 0;
                x3 = ii.x3;
                y3 = ii.y3;
            }
            //                        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            if ((gg1 || gg2 || gg3) && dis[x1][y1][x2][y2][x3][y3] == -1 && mp(x1, y1) != mp(x2, y2) && mp(x1, y1) != mp(x3, y3) && mp(x3, y3) != mp(x2, y2))
            {
                //                                dbg(444);
                dis[x1][y1][x2][y2][x3][y3] = dis[ii.x1][ii.y1][ii.x2][ii.y2][ii.x3][ii.y3] + 1;
                q.push(info(x1, y1, x2, y2, x3, y3));
            }
        }
    }
    if (ans == inf)
        puts("trapped");
    else
        pfn(ans);
}
void input()
{
    string s;
    v.clr;
    mem(obs, 0);
    mem(target, 0);
    st.clr;
    sf(n);
    For(i, n)
    {
        cin >> s;
        v.pb(s);
    }
    For(i, v.sz)
        For(j, v[0].sz) if (v[i][j] == '#')
            obs[i][j] = 1;
    else if (v[i][j] == 'X')
        target[i][j] = 1;
    else if (v[i][j] != '.')
        st.pb(mp(i, j));
    //        For(i,st.sz)
    //                cout << st[i].ff << " " << st[i].ss << endl;
}
int main()
{
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        input();
        CASE(cs++);
        bfs();
    }
    return 0;
}
