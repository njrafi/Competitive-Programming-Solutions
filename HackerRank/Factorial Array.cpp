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
#define mod 1000000000
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

int v[mxn];

i64 tree[4 * mxn][45], lazy[4 * mxn];
i64 fact[45];

void process()
{
        i64 ans = 1;
        fact[0] = 1;
        mem(lazy,0);
        for(int i = 1 ; ; i++)
        {
                ans = (ans * i ) % mod;
//                cout << i << " " << ans << endl;
                fact[i] = ans;
                if(!ans)
                        break;
        }
}

void traverse(int n,int st,int en)
{
        printf("in node: ");
        cout << n << " from " << st << " to " << en << " :";
        For(i,40)
                if(tree[n][i])
                        cout << i << " " << tree[n][i] << endl;
        cout << endl;

        if(st==en)
                return;
        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        traverse(lc,st,mid);
        traverse(rc,mid+1,en);

}

void build(int n,int st,int en)
{
        if(st==en)
        {
                mem(tree[n],0);
                if(v[st]<40)
                        tree[n][v[st]] = 1;
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        For(i,42)
                tree[n][i] = tree[lc][i] + tree[rc][i];
}

void process(int n,int st,int en,int val)
{
//        cout << st << " " << en << " " << val << endl;
        for(int i = 39 ; i>0 ; i--)
        {
                tree[n][i] = 0;
                if(i-val>=0)
                        tree[n][i] = tree[n][i-val];
        }

        lazy[n] = 0;
        int lc = 2 * n, rc = lc + 1;

        if(st!=en)
        {
                lazy[lc] += val;
                lazy[rc] += val;
        }
}


void update1(int n,int st,int en,int l,int r)
{
        if(l>r)
                return;
        if(lazy[n])
                process(n,st,en,lazy[n]);

        if(st>en || en<l || st>r)
                return;

        if(l<=st && en<=r)
        {
                process(n,st,en,1);
                return;
        }
        int mid = (st+en)/2 , lc = 2 *n  , rc = lc  + 1;

        update1(lc,st,mid,l,r);
        update1(rc,mid+1,en,l,r);

        For(i,42)
                tree[n][i] = tree[lc][i] + tree[rc][i];
}

void update2(int n,int st,int en,int idx,int val)
{
        if(lazy[n])
                process(n,st,en,lazy[n]);
        if(st==en)
        {
                mem(tree[n],0);
                if(val<40)
                        tree[n][val] = 1;
//                traverse(1,1,5);

                return;
        }
        int mid = (st+en)/2 , lc = 2 *n  , rc = lc  + 1;

        if(lazy[lc])
                process(lc,st,mid,lazy[lc]);
        if(lazy[rc])
                process(rc,mid+1,en,lazy[rc]);

        if(idx<=mid)
                update2(lc,st,mid,idx,val);
        else
                update2(rc,mid+1,en,idx,val);

        For(i,42)
                tree[n][i] = tree[lc][i] + tree[rc][i];
}


i64 query(int n,int st,int en,int l,int r)
{
        if(l>r)
                return 0;
        if(lazy[n])
                process(n,st,en,lazy[n]);

        if(st>en || en<l || st>r)
                return 0;

        if(l<=st && en<=r)
        {

                i64 ret = 0;
                For(i,40)
                        ret = (ret + ( (i64)tree[n][i] * fact[i]) % mod ) % mod;
                return ret;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc  = lc + 1;

        i64 p1 = query(lc,st,mid,l,r);
        i64 p2 = query(rc,mid+1,en,l,r);

        return (p1 + p2) % mod;


}

int main()
{

        process();
//        cout << fact[15] << endl;
//        For(i,40)
//                cout << i << " " << fact[i] << endl;
        int n,m , op , l , r;
        sff(n,m);

        Fre(i,1,n+1)
                sf(v[i]);

        build(1,1,n);

        while(m--)
        {
                sfff(op,l,r);
                if(op==1)
                        update1(1,1,n,l,r);
                else if(op==2)
                        cout << query(1,1,n,l,r) << endl;
                else if(op==3)
                        update2(1,1,n,l,r);
                else
                        traverse(1,1,n);
        }






        return 0;
}

