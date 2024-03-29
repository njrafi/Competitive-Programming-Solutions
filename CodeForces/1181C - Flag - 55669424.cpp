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
#define mxn 1003
int a[27][mxn][mxn];
int cum[27][mxn][mxn];
int n, m;
vs v;
int sum(int x1, int y1, int x2, int y2, int idx)
{
    if (x1 < 1 || y1 < 1 || x1 > n || y1 > m)
        return -1;
    //        x1++;
    //        y1++;
    //        x2++;
    //        y2++;
    // if 1 based dont change anything
    // if 0 based array comment out + handle input
    return cum[idx][x2][y2] - cum[idx][x2][y1 - 1] - cum[idx][x1 - 1][y2] + cum[idx][x1 - 1][y1 - 1];
}
bool ok(int x, int y, int height, int width)
{
    // cout <<x << " " << y <<  "gg" << height << " " << width << endl;
    int topx = x - height;
    if (topx < 1)
        return 0;
    int bottomx = x + height;
    if (bottomx > n)
        return 0;
    int l = v[x - 1][y - 1] - 'a';
    int tl = v[topx - 1][y - 1] - 'a';
    int bl = v[bottomx - 1][y - 1] - 'a';
    if (l == bl || l == tl)
        return 0;
    int ok = 0;
    if (sum(topx, y, topx + height - 1, y + width - 1, tl) == height * width)
        ok++;
    if (sum(x, y, x + height - 1, y + width - 1, l) == height * width)
        ok++;
    if (sum(bottomx, y, bottomx + height - 1, y + width - 1, bl) == height * width)
        ok++;
    if (ok == 3)
        return 1;
    return 0;
}
int main()
{
    sff(n, m);
    string s;
    For(i, n)
    {
        cin >> s;
        v.pb(s);
    }
    Fre(i, 1, n + 1)
        Fre(j, 1, m + 1)
    {
        int let = v[i - 1][j - 1] - 'a';
        a[let][i][j] = 1;
    }
    For(k, 26)
        Fre(i, 1, n + 2)
            Fre(j, 1, m + 1)
                cum[k][i][j] = cum[k][i][j - 1] + a[k][i][j];
    For(k, 26)
        Fre(i, 1, n + 2)
            Fre(j, 1, m + 2)
                cum[k][i][j] += cum[k][i - 1][j];
    //        while(1)
    //        {
    //                int x1,x2,y1,y2,gg;
    //                cin >> x1 >> x2 >> y1 >> y2 >> gg;
    //                cout << sum(x1,x2,y1,y2,gg) << endl;
    //        }
    i64 ans = 0;
    For(i, v.sz)
        For(j, v[i].sz)
    {
        if (i - 1 < 0 || v[i - 1][j] == v[i][j])
            continue;
        int height = 1;
        int row = i;
        while (row + 1 < v.sz && v[row + 1][j] == v[i][j])
        {
            height++;
            row++;
        }
        int lo = 1, hi = 1000, width = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            //                                cout << i + 1 << " sds " << j + 1 << " " << height << " " << mid << endl;
            if (ok(i + 1, j + 1, height, mid))
            {
                width = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        ans += width;
    }
    cout << ans << endl;
    return 0;
}