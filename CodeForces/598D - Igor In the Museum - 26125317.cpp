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
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "w", stdout)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
#define max_d 1005
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dp[1005][1005];
int vis[1005][1005], qx[1000006], qy[1000006];
int sx, sy, x, y;
vs v;
bool valid(int xx, int yy)
{
    if (xx >= 0 && yy >= 0 && xx < x && yy < y && v[xx][yy] != '*')
        return 1;
    return 0;
}
int bfs()
{
    int wx, wy, ans = 0;
    vpi vaa;
    int qf = 0, qb = 0;
    qx[qb] = sx;
    qy[qb] = sy;
    qb++;
    vis[sx][sy] = 1;
    while (qf != qb)
    {
        sx = qx[qf];
        sy = qy[qf];
        qf++;
        vaa.pb(mp(sx, sy));
        //cout << sx << " " << sy << endl;
        For(i, 4)
        {
            wx = sx + dx[i];
            wy = sy + dy[i];
            //   cout << wx <<" "<< wy << endl;
            if (!valid(wx, wy))
                ans++;
            if (valid(wx, wy) && !vis[wx][wy])
            {
                vis[wx][wy] = 1;
                qx[qb] = wx;
                qy[qb] = wy;
                qb++;
            }
        }
    }
    For(i, vaa.sz)
        dp[vaa[i].ff][vaa[i].ss] = ans;
    return ans;
}
int main()
{
    //READ;
    mem(dp, -1);
    For(i, 1005)
        For(j, 1005)
            vis[i][j] = 0;
    int t;
    string s;
    cin >> x >> y >> t;
    For(i, x)
    {
        cin >> s;
        v.pb(s);
    }
    //  For(i,v.sz)
    //  cout << v[i] << endl;
    while (t--)
    {
        scanf("%d %d", &sx, &sy);
        sx--;
        sy--;
        if (dp[sx][sy] != -1)
            printf("%d\n", dp[sx][sy]);
        else
            printf("%d\n", bfs());
    }
    return 0;
}