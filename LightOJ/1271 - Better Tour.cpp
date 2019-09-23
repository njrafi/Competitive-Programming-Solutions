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
#define READ freopen("test.txt", "r", stdin)
#define WRITE freopen("outDP.txt", "w", stdout)
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
    pc(' ');
}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 50004
vi v[mxn];
int dis[mxn];
int st, en;
void bfs()
{
    mem(dis, -1);
    queue<int> q;
    dis[en] = 0;
    q.push(en);
    while (!q.empty())
    {
        int u = q.front();
        //                cout << "bfs gg" << endl;
        q.pop();
        For(i, v[u].sz)
        {
            int vv = v[u][i];
            if (dis[vv] == -1)
            {
                dis[vv] = dis[u] + 1;
                if (vv == st)
                    return;
                q.push(vv);
            }
        }
    }
}
vi ans;
void f(int now)
{
    //        cout << "funAction gg" << endl;
    ans.pb(now);
    if (dis[now] == 1)
    {
        ans.pb(en);
        return;
    }
    int mn = inf;
    For(i, v[now].sz)
    {
        int vv = v[now][i];
        if (dis[vv] == dis[now] - 1)
            mn = min(mn, vv);
    }
    f(mn);
}
int main()
{
    int t, cs = 1, n, inp;
    fastRead(&t);
    while (t--)
    {
        mem(v, NULL);
        fastRead(&n);
        fastRead(&st);
        int last = st;
        For(i, n - 1)
        {
            fastRead(&en);
            v[last].pb(en);
            v[en].pb(last);
            last = en;
        }
        bfs();
        //                Fre(i,1,n+1)
        //                        cout << i << " " << dis[i] << endl;
        CASE(cs++);
        ans.clr;
        f(st);
        For(i, ans.sz)
        {
            if (i == ans.sz - 1)
                pfn(ans[i]);
            else
                fastWrite(ans[i]);
        }
    }
    return 0;
}
