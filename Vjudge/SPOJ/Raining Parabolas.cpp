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
#define mod 10007
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

#define mxn 100005


struct info
{
        i64 x,xx,a,b,c;
        info() {}
        info(i64 i,i64 aaa,i64 bbb,i64 ccc)
        {

                x = i % mod;
                xx = (i * i) % mod;
                a = aaa % mod;
                b = bbb % mod;
                c = ccc % mod;
        }
};



info merge(info lc,info rc)
{
        info gg;
        gg.a = (lc.a + rc.a) % mod;
        gg.b = (lc.b + rc.b) % mod;
        gg.c = (lc.c + rc.c) % mod;
        gg.x = (lc.x + rc.x) % mod;
        gg.xx = (lc.xx + rc.xx) % mod;

        return gg;
}


info tree[5 * mxn];
i64 ca[5 * mxn];
i64 cb[5 * mxn];
i64 cc[5 * mxn];

i64 a,b,c;


void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n] = info(st,0,0,0);
                return;
        }

        int mid = (st+en)/2, lc = 2 * n, rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = merge(tree[lc],tree[rc]);
}

void process(int n,int st,int en,i64 a,i64 b,i64 c)
{
        tree[n].a = ( tree[n].a + ( a * tree[n].xx ) % mod  ) % mod;
        tree[n].b = ( tree[n].b + ( b * tree[n].x ) % mod  ) % mod;
        tree[n].c = ( tree[n].c +  (c * (en-st+1)) % mod ) % mod;

        int lc = 2 * n, rc = lc + 1;




        ca[lc] = (ca[lc] + a) % mod;
        ca[rc] = (ca[rc] + a) % mod;
        ca[n] = 0;



        cb[lc] = (cb[lc] + b) % mod;
        cb[rc] = (cb[rc] + b) % mod;
        cb[n] = 0;


        cc[lc] = (cc[lc] + c) % mod;
        cc[rc] = (cc[rc] + c) % mod;
        cc[n] = 0;

}


void update(int n,int st,int en,int l,int r)
{
//        cout << n << endl;
        process(n,st,en,ca[n],cb[n],cc[n]);

        if(r<st || en<l)
                return;

        if(l<=st && en<=r)
        {
                process(n,st,en,a,b,c);
                return;
        }
        int mid = (st+en)/2, lc = 2 * n, rc = lc + 1;

        update(lc,st,mid,l,r);
        update(rc,mid+1,en,l,r);

        tree[n] = merge(tree[lc],tree[rc]);

}


info query(int n,int st,int en,int l,int r)
{
        process(n,st,en,ca[n],cb[n],cc[n]);

        if(r<st || en<l)
                return info(0,0,0,0);

        if(l<=st && en<=r)
                return tree[n];

        int mid = (st+en)/2, lc = 2 * n, rc = lc + 1;

        info q1 = query(lc,st,mid,l,r);
        info q2 = query(rc,mid+1,en,l,r);


        return merge(q1,q2);
}


int main()
{


        int n,q,op,x,y;
        sff(n,q);

        build(1,0,n-1);

//        dbg(123);

        while(q--)
        {
                sfff(op,x,y);
                if(op==1)
                {
                        info q = query(1,0,n-1,x,y);

                        pfn( ( q.a + q.b + q.c ) % mod);
//                        cout << q.a << " " << q.b << " " << q.c << endl;
                }
                else
                {
                        sfff(a,b,c);
                        update(1,0,n-1,x,y);
                }
        }











        return 0;
}