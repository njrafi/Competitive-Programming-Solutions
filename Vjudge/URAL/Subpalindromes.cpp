#include <bits/stdc++.h>


    #define gc getchar
    #define pc putchar

using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define ui64 unsigned long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX/2
#define infll LLONG_MAX/3
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


//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

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

#define mxn 100005
#define pr 41
ui64 pp[mxn];



/// the hash value and size
pair<ui64,int> tree[3][4 * mxn];
char s[2][mxn];


/// gg = 0 soja , gg = 1 means ulta
void update(int n,int st,int en,int idx,int val,int gg)
{
        if(st==en)
        {
                tree[gg][n] = mp(val,1);
                return;
        }

        int mid = (st + en) / 2, lc = 2 * n , rc = lc + 1;

        if(idx<=mid)
                update(lc,st,mid,idx,val,gg);
        else
                update(rc,mid+1,en,idx,val,gg);

        tree[gg][n].ff = tree[gg][lc].ff * pp[tree[gg][rc].ss] + tree[gg][rc].ff;
        tree[gg][n].ss = tree[gg][lc].ss + tree[gg][rc].ss;
}


pair<ui64,int> query(int n,int st,int en,int l,int r,int gg)
{
        if(r < st || en < l)
                return mp(0,0);

        if(l<=st && en<=r)
                return tree[gg][n];


        int mid = (st + en) / 2, lc = 2 * n , rc = lc + 1;

        pair<ui64,int> q1 = query(lc,st,mid,l,r,gg);
        pair<ui64,int> q2 = query(rc,mid+1,en,l,r,gg);
        pair<ui64,int> q;

        q.ff = q1.ff * pp[q2.ss] + q2.ff;
        q.ss = q1.ss + q2.ss;

        return q;

}



void pre(int n)
{
        pp[0] = 1;

        Fre(i,1,mxn)
                pp[i] = pp[i-1] * pr;


        For(i,n)
                update(1,1,n,i+1,s[0][i],0);

        strcpy(s[1],s[0]);

        for(int i = n - 1 , j = 0 ; i >= 0 ;i-- , j++)
                s[1][j] = s[0][i];

        For(i,n)
                update(1,1,n,i+1,s[1][i],1);
}


char op[15],cc[3];
int main()
{
        int l,r,q,n;

        scanf("%s", s[0]);
        n = strlen(s[0]);
        pre(n);


        fastRead(&q);
        while(q--)
        {
                scanf("%s",op);

                if(op[0]=='c')
                {
                        fastRead(&l);
                        scanf("%s",cc);
                        r = cc[0];
//                        cout << l << " " << r << endl;
                        update(1,1,n,l,r,0);

                        l = n - l + 1;

                        update(1,1,n,l,r,1);
                }
                else
                {
                        fastRead(&l);
                        fastRead(&r);
                        ui64 qs = query(1,1,n,l,r,0).ff;

                        int ll = n - r + 1;
                        int rr = n - l + 1;

                        ui64 qu = query(1,1,n,ll,rr,1).ff;

                        if(qs==qu)
                                puts("Yes");
                        else
                                puts("No");
                }
        }













        return 0;
}