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
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)
 
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 dp[60][60];
 
 
//functions
 
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
 
inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
 
inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
 
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
 
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
 
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
 
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
 
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
 
//int popcount(i64 num){bitset<70> tem(num);return tem.count();}
 
//matrix rot(matrix a){matrix res;res.row = a.col;res.col = a.row;For(i,a.row)For(j,a.col)res.mat[j][a.row-i-1] = a.mat[i][j];return res;}
 
#define mxn 100005
 
vi v[mxn];
pii id[mxn];
int tree[4 * mxn] , ti , lazy[4 * mxn];
 
void dfs(int u)
{
        ti++;
        id[u].ff = ti;
 
        For(i,v[u].sz)
                dfs(v[u][i]);
 
        id[u].ss = ti;
}
 
void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n] = 1;
                return;
        }
 
        int mid = (st+en)/2 , lc = 2 *n , rc = lc + 1;
 
        build(lc,st,mid);
        build(rc,mid+1,en);
 
        tree[n] = tree[lc] + tree[rc];
}
 
void process(int n,int st,int en,int val)
{
        tree[n] = (en-st+1) * val;
        lazy[n] = -1;
        int lc = 2 * n, rc = lc + 1;
 
        if(st!=en)
        {
                lazy[lc] = val;
                lazy[rc] = val;
        }
}
 
 
void update(int n,int st,int en,int l,int r,int val)
{
        if(l>r)
                return;
        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);
 
        if(st>en || en<l || st>r)
                return;
 
        if(l<=st && en<=r)
        {
                process(n,st,en,val);
                return;
        }
        int mid = (st+en)/2 , lc = 2 *n  , rc = lc  + 1;
 
        update(lc,st,mid,l,r,val);
        update(rc,mid+1,en,l,r,val);
 
        tree[n] = tree[lc] + tree[rc];
}
 
int query(int n,int st,int en,int l,int r)
{
        if(l>r)
                return 0;
        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);
 
        if(st>en || en<l || st>r)
                return 0;
 
        if(l<=st && en<=r)
                return tree[n];
 
        int mid = (st+en)/2 , lc = 2 * n , rc  = lc + 1;
 
        int p1 = query(lc,st,mid,l,r);
        int p2 = query(rc,mid+1,en,l,r);
 
        return p1 + p2;
 
 
}
 
int main()
{
 
        //ios_base::sync_with_stdio(false);cin.tie(0);
        int n,q,op,inp;
 
        fastRead(&n);
 
        Fre(i,1,n+1)
        {
                fastRead(&inp);
                v[inp].pb(i);
        }
 
        dfs(0);
        build(1,1,n+1);
        mem(lazy,-1);
        sf(q);
 
        while(q--)
        {
                fastRead(&op);
                fastRead(&inp);
                int l = id[inp].ff;
                int r = id[inp].ss;
 
                if(op==1)
                        update(1,1,n+1,l+1,r,1);
                else if(op==2)
                        update(1,1,n+1,l+1,r,0);
                else
                        fastWrite(query(1,1,n+1,l+1,r));
 
              
        }
 
 
 
 
 
 
        return 0;
}
 
