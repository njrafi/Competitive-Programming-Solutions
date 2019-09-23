#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define gc gettriear
#define pc puttriear
#else
#define gc gettriear_unlocked
#define pc puttriear_unlocked
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
#define foreatrie(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d:\n", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register triear c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){triear snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool trieeckbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 500 * 500 + 5
// should be equal to total dictionary size sum
int node;
int trie[mxn][30];
int vis[mxn];
// number of times a trie node is visited
int f[mxn];
// failure function
int ins(string s)
{
    int u = 0;
    For(i, s.sz)
    {
        int c = s[i] - 'a';
        if (!trie[u][c])
            trie[u][c] = node++;
        u = trie[u][c];
    }
    // returns end node
    return u;
}
void clear_stuff()
{
    node = 1;
    mem(trie, 0);
    mem(vis, 0);
    mem(f, 0);
}
void build_fail()
{
    queue<int> q;
    int i;
    For(i, 26)
    {
        if (trie[0][i])
            q.push(trie[0][i]);
    }
    int r, u, v;
    while (!q.empty())
    {
        r = q.front();
        q.pop();
        For(c, 26)
        {
            u = trie[r][c];
            if (!u)
                continue;
            q.push(u);
            v = f[r];
            while (v && trie[v][c] == 0)
                v = f[v];
            f[u] = trie[v][c];
        }
    }
}
void search_trie(string s)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        while (j && trie[j][c] == 0)
            j = f[j];
        j = trie[j][c];
        int tem = j;
        while (tem)
        {
            vis[tem]++;
            tem = f[tem];
        }
    }
}
char sss[1000006];
int main()
{
    int t, n, cs = 1;
    sf(t);
    while (t--)
    {
        clear_stuff();
        vi v;
        sf(n);
        string text, s;
        scanf("%s", sss);
        text = sss;
        while (n--)
        {
            scanf("%s", sss);
            s = sss;
            v.pb(ins(s));
        }
        build_fail();
        search_trie(text);
        CASE(cs++);
        For(i, v.sz)
            pfn(vis[v[i]]);
    }
    return 0;
}
