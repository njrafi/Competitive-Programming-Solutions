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


i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

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
        i64 sum,sq,mx,mn;
        info()
        {
                sum = 0;
                sq = 0;
                mx = -infll;
                mn = infll;
        }
        info(int num)
        {
                sum = num;
                mx = num;
                mn = num;
                sq = num * num;
        }
};

info tree[4 * mxn];
int v[mxn];
i64 lazy1[4 * mxn];
i64 lazy2[4 * mxn];
bool lazy1gg[4 * mxn];
bool lazy2gg[4 * mxn];

info mergegg(info a,info b)
{
        a.mx = max(a.mx,b.mx);
        a.mn = min(a.mn,b.mn);
        a.sum += b.sum;
        a.sq += b.sq;

        return a;
}

void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n] = info(v[st]);
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = mergegg(tree[lc],tree[rc]);
}


void lazy_update(int n,int st,int en)
{
        int lc = 2 * n , rc = lc + 1;
        if(lazy1gg[n])
        {
                i64 val = lazy1[n];
                lazy1[n] = 0;
                lazy1gg[n] = 0;


                tree[n].sq = (en - st + 1) * val * val;
                tree[n].sum = (en-st+1) * val;
                tree[n].mx = val;
                tree[n].mn = val;


                if(st!=en)
                {
                        lazy1[lc] = val;
                        lazy1[rc] = val;
                        lazy2[lc] = 0;
                        lazy2[rc] = 0;

                        lazy1gg[lc] = 1;
                        lazy1gg[rc] = 1;
                        lazy2gg[lc] = 0;
                        lazy2gg[rc] = 0;

                }
        }

        if(lazy2gg[n])
        {
                i64 val = lazy2[n];
                lazy2[n] = 0;
                lazy2gg[n] = 0;


                tree[n].sq += (en - st + 1) * val * val + 2 * val * tree[n].sum;
                tree[n].sum += (en-st+1) * val;
                tree[n].mx += val;
                tree[n].mn += val;

                if(st!=en)
                {

                        lazy2[lc] += val;

                        lazy2[rc] += val;


                        lazy2gg[lc] = 1;

                        lazy2gg[rc] = 1;
                }
        }
}


void process(int n,int st,int en,i64 val,int id)
{
        int lc = 2 * n , rc = lc + 1;

        /// direct change
        if(!id)
        {
                tree[n].sq = (en - st + 1) * val * val ;
                tree[n].sum = (en-st+1) * val;
                tree[n].mx = val;
                tree[n].mn = val;


                if(st!=en)
                {
                        lazy1[lc] = val;
                        lazy1[rc] = val;
                        lazy2[lc] = 0;
                        lazy2[rc] = 0;

                        lazy1gg[lc] = 1;
                        lazy1gg[rc] = 1;
                        lazy2gg[lc] = 0;
                        lazy2gg[rc] = 0;
                }
        }
        else
        {
                tree[n].sq += (en - st + 1) * val * val + 2 * val * tree[n].sum;
                tree[n].sum += (en-st+1) * val;
                tree[n].mx += val;
                tree[n].mn += val;

                if(st!=en)
                {

                        lazy2[lc] += val;
                        lazy2[rc] += val;
                        lazy2gg[lc] = 1;
                        lazy2gg[rc] = 1;
                }
        }
}

void update(int n,int st,int en,int l,int r,i64 val,int id)
{
        lazy_update(n,st,en);
        if(r<st || en<l)
                return;

        if(l<=st && en<=r)
        {
                process(n,st,en,val,id);
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        update(lc,st,mid,l,r,val,id);
        update(rc,mid+1,en,l,r,val,id);

        tree[n] = mergegg(tree[lc],tree[rc]);


}
info query(int n,int st,int en,int l,int r)
{

        lazy_update(n,st,en);
        if(r<st || en<l)
                return info();

        if(l<=st && en<=r)
                return tree[n];

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        info q1 = query(lc,st,mid,l,r);
        info q2 = query(rc,mid+1,en,l,r);

        return mergegg(q1,q2);
}


int main()
{


        int t,n,q,inp,op,l,r,cs = 1;
        sf(t);

        while(t--)
        {
                sff(n,q);

                Fre(i,1,n+1)
                        sf(v[i]);

                mem(lazy1,0);
                mem(lazy2,0);
                mem(lazy1gg,0);
                mem(lazy1gg,0);


                build(1,1,n);

                CASE(cs++);

                while(q--)
                {
                        sf(op);
                        if(op==2)
                        {
                                sff(l,r);
                                info q = query(1,1,n,l,r);
                                i64 m = r - l + 1;

                                i64 up = m * q.sq - sqr(q.sum);
                                i64 down = m * m;
                                i64 gg = gcd(up,down);

                                up /= gg;
                                down /= gg;
//                                cout << q.sum << " " << q.sq << endl;

                                printf("%lld/%lld %lld\n",up,down,q.mx - q.mn);
//                                cout << up << "/" << down << " ";
//                                cout << q.mx - q.mn << endl;
                        }
                        else
                        {
                                sfff(l,r,inp);
                                update(1,1,n,l,r,inp,op);
                        }
                }
        }












        return 0;
}