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
#define CASE(a) printf("Case %d: ", a)
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
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
char st[5], des[5];
bool bad[28][28][28];
int lev[28][28][28];
struct node
{
    int x, y, z;
};
int bfs()
{
    mem(lev, -1);
    if (bad[st[0] - 'a'][st[1] - 'a'][st[2] - 'a'])
        return -1;
    lev[st[0] - 'a'][st[1] - 'a'][st[2] - 'a'] = 0;
    queue<node> q;
    node tem;
    tem.x = st[0] - 'a';
    tem.y = st[1] - 'a';
    tem.z = st[2] - 'a';
    q.push(tem);
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        For(i, 6)
        {
            int xx = (u.x + dx[i] + 26) % 26;
            int yy = (u.y + dy[i] + 26) % 26;
            int zz = (u.z + dz[i] + 26) % 26;
            if (!bad[xx][yy][zz] && lev[xx][yy][zz] == -1)
            {
                lev[xx][yy][zz] = lev[u.x][u.y][u.z] + 1;
                if (lev[des[0] - 'a'][des[1] - 'a'][des[2] - 'a'] != -1)
                    break;
                node tem;
                tem.x = xx;
                tem.y = yy;
                tem.z = zz;
                q.push(tem);
            }
        }
        if (lev[des[0] - 'a'][des[1] - 'a'][des[2] - 'a'] != -1)
            break;
    }
    return lev[des[0] - 'a'][des[1] - 'a'][des[2] - 'a'];
}
int main()
{
    int t, n, cs = 1;
    char a[30], b[30], c[30];
    fastRead(&t);
    while (t--)
    {
        scanf("%s %s", st, des);
        mem(bad, 0);
        fastRead(&n);
        while (n--)
        {
            scanf("%s %s %s", a, b, c);
            int aa = strlen(a);
            int bb = strlen(b);
            int cc = strlen(c);
            For(i, aa)
                For(j, bb)
                    For(k, cc)
                        bad[a[i] - 'a'][b[j] - 'a'][c[k] - 'a'] = 1;
        }
        CASE(cs++);
        pfn(bfs());
    }
    return 0;
}
