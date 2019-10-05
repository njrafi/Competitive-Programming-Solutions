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

#define mxn 400005

int tree[mxn * 4] , lazy[mxn * 4];
mpi m;
vi v,p;
vector< pair < int, pair < int , pii > > >  seg;

void process(int n,int st,int en,int val)
{
        tree[n] =  val;
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
        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);

        if(en<l || st>r)
                return;

        if(l<=st && en<=r)
        {
                process(n,st,en,val);
                return;
        }
        int mid = (st+en)/2 , lc = 2 *n  , rc = lc  + 1;

        update(lc,st,mid,l,r,val);
        update(rc,mid+1,en,l,r,val);
}

int query(int n,int st,int en,int idx)
{

        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);
        if(st==en)
                return tree[n];

        int mid = (st+en)/2 , lc = 2 * n , rc  = lc + 1;
        if(idx<=mid)
                return query(lc,st,mid,idx);
        else
                return query(rc,mid+1,en,idx);


}



int main()
{

        int n,a,b,q,inp;
        sf(n);
        Fre(i,1,n+1)
        {
                sff(a,b);
                seg.pb(mp(-(b-a+1),mp(i,mp(a,b))));
                v.pb(a);
                v.pb(b);
        }

        sf(q);
        while(q--)
        {
                sf(inp);
                p.pb(inp);
                v.pb(inp);
        }

        sort(all(v));
        int now = 1;
        For(i,v.sz)
                if(m.find(v[i])==m.end())
                        m[v[i]] = now++;

        mem(lazy,-1);
        mem(tree,-1);
        sort(all(seg));
        //reverse(all(seg));
       // cout << now << endl;
        For(i,seg.sz)
        {
                int l = m[seg[i].ss.ss.ff];
                int r = m[seg[i].ss.ss.ss];
              //  cout << l << " " << r << " " << seg[i].ss.ff << endl;
                update(1,1,now,l,r,seg[i].ss.ff);
        }

        For(i,p.sz)
        {
                int gg = m[p[i]];
                pfn(query(1,1,now,gg));
        }


      //  cout << now << endl;







        return 0;
}