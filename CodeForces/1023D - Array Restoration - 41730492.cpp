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
#define mxn 200005
int v[mxn];
int tree[4 * mxn];
void build(int n, int st, int en)
{
    if (st == en)
    {
        tree[n] = v[st];
        return;
    }
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    build(lc, st, mid);
    build(rc, mid + 1, en);
    tree[n] = min(tree[lc], tree[rc]);
}
int query(int n, int st, int en, int l, int r)
{
    if (r < st || en < r)
        return inf;
    if (l <= st && en <= r)
        return tree[n];
    int mid = (st + en) / 2, lc = 2 * n, rc = lc + 1;
    int q1 = query(lc, st, mid, l, r);
    int q2 = query(rc, mid + 1, en, l, r);
    return min(q1, q2);
}
int l[mxn], r[mxn];
vi temp[mxn], temn[mxn];
int main()
{
    int n, m;
    sff(n, m);
    mem(l, -1);
    mem(r, -1);
    int zer = -1;
    Fre(i, 1, n + 1)
    {
        sf(v[i]);
        if (!v[i])
        {
            v[i] = inf;
            zer = i;
            continue;
        }
        if (l[v[i]] == -1)
            l[v[i]] = i;
        r[v[i]] = i;
    }
    build(1, 1, n);
    for (int i = m; i > 0; i--)
    {
        //                cout << i << " " << l[i] << " " << r[i] << endl;
        if (l[i] == -1)
        {
            if (i == m)
            {
                if (zer == -1)
                {
                    puts("NO");
                    return 0;
                }
                l[i] = zer;
                r[i] = zer;
            }
            else
            {
                l[i] = l[i + 1];
                r[i] = r[i + 1];
            }
        }
        int mn = query(1, 1, n, l[i], r[i]);
        if (mn < i)
        {
            puts("NO");
            return 0;
        }
        //                cout << l[i] << " " << r[i] << endl;
        temp[l[i]].pb(i);
        temn[r[i] + 1].pb(i);
    }
    si s;
    si::iterator it;
    Fre(i, 1, n + 1)
    {
        For(j, temn[i].sz)
            s.erase(temn[i][j]);
        For(j, temp[i].sz)
            s.insert(temp[i][j]);
        if (s.empty())
            continue;
        it = s.end();
        it--;
        //  pfs(*it);
        if (v[i] == inf || v[i] == *it)
        {
            v[i] = *it;
        }
        else
        {
            puts("NO");
            return 0;
        }
    }
    Fre(i, 2, n + 1) if (v[i] == inf && v[i - 1] != inf)
        v[i] = v[i - 1];
    for (int i = n - 1; i > 0; i--)
        if (v[i] == inf && v[i + 1] != inf)
            v[i] = v[i + 1];
    puts("YES");
    Fre(i, 1, n + 1)
        pfs(v[i]);
    return 0;
}
