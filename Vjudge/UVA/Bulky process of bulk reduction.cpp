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
#define CASE(a) printf("Case %d:\n",a)

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


#define mxn 100005

struct info
{
        i64 x,sumx,sum;
        info() {}
        info(i64 xx,int val)
        {
                x = xx;
                sum = val;
                sumx = (val * xx) % mod;
        }
};


info tree[4 * mxn];
i64 lazy[4 * mxn];

info merge(info lc,info rc)
{
        info ret;
        ret.x = lc.x + rc.x ;
        ret.sum = lc.sum + rc.sum;
        ret.sumx = lc.sumx + rc.sumx;

        return ret;
}


void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n] = info(st,100);
                return;
        }

        int mid = (st+en)/2, lc = 2 * n, rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = merge(tree[lc],tree[rc]);
}






void process(int n,int st,int en,i64 sum)
{
        tree[n].sum = (tree[n].sum + ( sum * (en-st+1) )  ) ;
        tree[n].sumx = (tree[n].sumx + (sum * tree[n].x) ) ;

        lazy[n] = 0;

        int lc = 2 * n , rc = lc + 1;

        if(st!=en)
        {
                lazy[lc] = (lazy[lc] + sum) % mod;
                lazy[rc] = (lazy[rc] + sum) % mod;
        }
}


void update(int n,int st,int en,int l,int r,i64 val)
{
        process(n,st,en,lazy[n]);

        if(r<st || en<l)
                return ;

        if(l<=st && en<=r)
        {
                process(n,st,en,val);
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n ,rc = lc + 1;

        update(lc,st,mid,l,r,val);
        update(rc,mid+1,en,l,r,val);

        tree[n] = merge(tree[lc],tree[rc]);

}





info query(int n,int st,int en,int l,int r)
{
        process(n,st,en,lazy[n]);

        if(r<st || en<l)
                return info(0,0);

        if(l<=st && en<=r)
                return tree[n];

        int mid = (st+en)/2, lc = 2 * n, rc = lc + 1;
        info q1 = query(lc,st,mid,l,r);
        info q2 = query(rc,mid+1,en,l,r);


        return merge(q1,q2);
}


int main()
{
        int t, n, inp, d, q, l, r, cs = 1;
        char op[10];

        sf(t);
        while(t--)
        {
                mem(lazy,0);
                sff(n,q);


                build(1,1,n);

                CASE(cs++);
                while(q--)
                {
                        scanf("%s",op);

                        if(op[0]=='q')
                        {
                                sff(l,r);

                                info q = query(1,1,n,l,r);

                                i64 ans = q.sumx - (l-1) * q.sum;


                                printf("%lld\n",ans);
                        }
                        else
                        {
                                sfff(l,r,d);

                                update(1,1,n,l,r,d);
                        }
                }
        }

        return 0;
}