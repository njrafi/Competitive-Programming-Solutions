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
#define i63 long long int
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
//i63 gcd(i63 a,i63 b){if(!b)return a;return gcd(b,a%b);}
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
//i63 bigmod(i63 num,i63 n){if(n==0)return 1;i63 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i63 modinverse(i63 num){return bigmod(num,mod-2)%mod;}
//i63 po(i63 a,i63 b){i63 ans=1;while(b--)ans *= a;return ans;}
//i63 ncr(i63 n,i63 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int tar[3][3];
pii tarpos[18];
int v[3][3];
/// checking the number of inversion
/// If its even then its solvable
bool solvable()
{
    int sum = 0;
    For(i, 9)
    {
        Fre(j, i + 1, 9)
        {
            if (tar[j / 3][j % 3] < tar[i / 3][i % 3])
            {
                if (tar[j / 3][j % 3])
                    sum++;
            }
        }
    }
    return ((sum % 2) == 0);
}
int pre()
{
    pii pos[9];
    For(i, 3)
        For(j, 3)
            tarpos[tar[i][j]] = mp(i, j);
}
int H()
{
    int ans = 0;
    For(i, 3)
        For(j, 3) if (v[i][j])
    {
        ans += abs(tarpos[v[i][j]].ff - i);
        ans += abs(tarpos[v[i][j]].ss - j);
    }
    //        cout << ans << endl;
    //        getchar();
    return ans;
}
int ida_d, solved;
int path[200];
//int movname[] = {'D','L','R','U'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, +1, 0};
bool valid(int x, int y)
{
    if (x >= 0 && y >= 0 && x < 3 && y < 3)
        return 1;
    return 0;
}
int ida(int lvl, int hv, int x, int y, int pre)
{
    //        if(lvl>35)
    //                return lvl;
    if (!hv)
    {
        solved = 1;
        fastWrite(lvl);
        //      For(i,lvl)
        //          cout << (char)path[i];
        //      cout << endl;
        return lvl;
    }
    if (lvl + hv > ida_d)
        return lvl + hv;
    int mn = inf;
    For(i, 4)
    {
        if (pre + i == 3)
            continue;
        //      path[lvl] = movname[i];
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!valid(xx, yy))
            continue;
        swap(v[x][y], v[xx][yy]);
        mn = min(mn, ida(lvl + 1, H(), xx, yy, i));
        swap(v[x][y], v[xx][yy]);
        if (solved)
            return mn;
    }
    return mn;
}
int main()
{
    int t, cs = 1;
    sf(t);
    while (t--)
    {
        int k = 1;
        For(i, 3)
            For(j, 3)
                v[i][j] = k++;
        v[2][2] = 0;
        int x, y;
        For(i, 3)
            For(j, 3)
                fastRead(&tar[i][j]);
        pre();
        CASE(cs++);
        if (!solvable())
        {
            puts("impossible");
            continue;
        }
        solved = 0;
        ida_d = H();
        while (!solved)
            ida_d = ida(0, H(), 2, 2, 10);
        if (!solved)
        {
            puts("impossible");
            continue;
        }
    }
    return 0;
}
