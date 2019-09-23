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
#define mxn 300005
vi v;
int pos[mxn];
int n;
vpi ans;
void print()
{
    Fre(i, 1, v.sz)
            cout
        << v[i] << " ";
    cout << endl;
}
void f(int i, int j)
{
    pos[v[i]] = j;
    pos[v[j]] = i;
    //        cout << i << " " << j << endl;
    ans.pb({i, j});
    assert(2 * abs(j - i) >= n);
    swap(v[i], v[j]);
    //        print();
}
int main()
{
    //READ;
    int inp;
    sf(n);
    v.pb(0);
    Fre(i, 1, n + 1)
    {
        sf(inp);
        v.pb(inp);
        pos[inp] = i;
    }
    if (pos[1] - 1 < n / 2)
        f(pos[1], pos[1] + n / 2);
    f(1, pos[1]);
    if (pos[n] != n)
    {
        //                cerr << "lala" << endl;
        if (n - pos[n] < n / 2)
        {
            f(1, n);
            f(pos[n], 1);
            f(1, n);
        }
        else
            f(pos[n], n);
    }
    Fre(i, 2, n - 1)
    {
        if (i == pos[i])
            continue;
        //                cerr << "doing " << i << endl;
        int x = i;
        int y = pos[i];
        if (x > y)
            swap(x, y);
        if (y - 1 < n / 2)
        {
            f(n, y);
            f(x, n);
            f(n, y);
        }
        else if (n - x < n / 2)
        {
            f(1, y);
            f(x, 1);
            f(1, y);
        }
        else
        {
            f(x, n);
            f(1, n);
            f(1, y);
            f(1, n);
            f(x, n);
        }
    }
    //        Fre(i,1,v.sz)
    //                cout << v[i] << " ";
    //        cout << endl;
    vi w = v;
    sort(all(w));
    assert(v == w);
    cout << ans.sz << endl;
    For(i, ans.sz)
            cout
        << ans[i].ff << " " << ans[i].ss << endl;
    return 0;
}
