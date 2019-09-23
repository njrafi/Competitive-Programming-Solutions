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
#define vll vector<i64>
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
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
//matrix rot(matrix a){matrix res;res.row = a.col;res.col = a.row;For(i,a.row)For(j,a.col)res.mat[j][a.row-i-1] = a.mat[i][j];return res;}
int mat[605][605];
int node[605];
int sou = 601, sink = 602;
int par[605];
int mxf;
int d, n, m;
vs v;
vi gr[605];
vi getpath()
{
    vi path;
    path.pb(sink);
    int now = sink;
    while (now != sou)
    {
        now = par[now];
        path.pb(now);
    }
    reverse(all(path));
    return path;
}
bool bfs()
{
    bool vis[605] = {0};
    vis[sou] = 1;
    queue<int> q;
    q.push(sou);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        Fre(i, 1, 605) if (mat[u][i] > 0 && !vis[i])
        {
            vis[i] = 1;
            par[i] = u;
            q.push(i);
        }
    }
    if (!vis[sink])
        return 0;
    vi path = getpath();
    int mn = 1234567;
    For(i, path.sz - 1)
    {
        // cout << path[i] << " " << path[i+1] << endl;
        mat[path[i]][path[i + 1]] -= 1;
        mat[path[i + 1]][path[i]] += 1;
    }
    mxf = 1;
    return 1;
}
int flow()
{
    int ans = 0;
    while (bfs())
        ans += mxf;
    return ans;
}
int f(string s, int st)
{
    int ans = 0;
    Fre(i, st, st + 3)
        ans += s[i] - '0';
    return ans;
}
pii findpair(int ind)
{
    int next = ind + d;
    int ff = 0;
    if (mat[ind][next])
    {
        next = ind + 2 * d;
        ff = 1;
    }
    For(i, gr[next].sz) if (!mat[next][gr[next][i]])
    {
        int tem = gr[next][i];
        while (tem > n + m)
            tem -= d;
        return mp(ff, tem);
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    v.pb("gg");
    //mem(mat,-1);
    READ;
    WRITE;
    string s;
    sff(n, m);
    d = n + m;
    Fre(i, 1, n + 1)
    {
        cin >> s;
        v.pb(s);
        mat[sou][i] = 1;
        mat[i][i + d] = 1;
        node[i + d] = f(s, 0);
        mat[i][i + 2 * d] = 1;
        node[i + 2 * d] = f(s, 3);
    }
    Fre(i, n + 1, n + m + 1)
    {
        cin >> s;
        v.pb(s);
        mat[i][sink] = 1;
        mat[i + d][i] = 1;
        node[i + d] = f(s, 0);
        mat[i + 2 * d][i] = 1;
        node[i + 2 * d] = f(s, 3);
    }
    Fre(i, 1, n + 1)
    {
        int l = i + d;
        Fre(j, n + 1, n + m + 1)
        {
            int r = j + 2 * d;
            if (node[l] == node[r])
            {
                mat[l][r] = 1;
                mat[r][l] = 0;
                gr[l].pb(r);
            }
        }
        l = i + 2 * d;
        Fre(j, n + 1, n + m + 1)
        {
            int r = j + d;
            if (node[l] == node[r])
            {
                mat[l][r] = 1;
                mat[r][l] = 0;
                gr[l].pb(r);
            }
        }
    }
    cout << flow() << endl;
    Fre(i, 1, n + 1) if (!mat[sou][i])
    {
        pii ans = findpair(i);
        if (ans.ff)
            cout << "TA"
                 << " " << v[ans.ss] << " " << v[i] << endl;
        else
            cout << "AT"
                 << " " << v[i] << " " << v[ans.ss] << endl;
    }
    return 0;
}
