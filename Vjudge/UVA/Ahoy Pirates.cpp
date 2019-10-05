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

#define mxn 1024005
string s,tem;
int tree[4 * mxn] ;
int lazy[4 * mxn];

void build(int n,int st,int en)
{
        if(st==en)
        {
                tree[n] = s[st] - '0';
                return;
        }

        int mid = (st+en)/ 2 , lc = 2 * n , rc = lc + 1;

        build(lc,st,mid);
        build(rc,mid+1,en);

        tree[n] = tree[lc] + tree[rc];
}

int gg(int val)
{
        if(val==-1)
                return 2;
        if(val==2)
                return -1;
        return 1-val;
}

void process(int n,int st,int en,int val)
{
        int lc = 2 * n , rc = lc + 1;

        if(val<2)
        {
                tree[n] = (en-st+1) * val;
                lazy[n] = -1;

                if(st!=en)
                {
                        lazy[lc] = val;
                        lazy[rc] = val;
                }
        }
        else
        {
                tree[n] = (en-st+1) - tree[n];
                lazy[n] = -1;

                if(st!=en)
                {
                        lazy[lc] = gg(lazy[lc]);
                        lazy[rc] = gg(lazy[rc]);
                }
        }
}

void update(int n,int st,int en,int l,int r,int val)
{

        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);

        if(l>r || en<l || r<st)
                return;
        if(l<=st && en <=r)
        {
                process(n,st,en,val);
                return;
        }

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        update(lc,st,mid,l,r,val);
        update(rc,mid+1,en,l,r,val);

        tree[n] = tree[lc] + tree[rc];

}

int query(int n,int st,int en,int l,int r)
{

       // dbg(n);
        if(lazy[n]!=-1)
                process(n,st,en,lazy[n]);

        if(l>r || en<l || r<st)
                return 0;

        if(l<=st && en<=r)
                return tree[n];

        int mid = (st+en)/2 , lc = 2 * n , rc = lc + 1;

        return query(lc,st,mid,l,r) + query(rc,mid+1,en,l,r);
}


void print()
{
        For(i,s.sz)
                cout << query(1,0,s.sz-1,i,i);
        cout << endl;
}

int main()
{
        int t,m,n,q,a,b , cs = 1;
       // WRITE;
        sf(t);
        while(t--)
        {
                mem(lazy,-1);
                sf(m);
                s.clr;
                while(m--)
                {
                        sf(n);
                        cin >> tem;
                        while(n--)
                                s += tem;
                }
                //cout << s << endl;
                CASE(cs++);
                int qno = 1;
                build(1,0,s.sz-1);
                sf(q);
                char op[3];
                Fre(i,1,q+1)
                {
                        scanf("%s",op) ;
                        sff(a,b);
                        if(op[0]=='F')
                                update(1,0,s.sz-1,a,b,1);
                        else if(op[0]=='E')
                                update(1,0,s.sz-1,a,b,0);
                        else if(op[0]=='I')
                                update(1,0,s.sz-1,a,b,2);
                        else
                        {

                                printf("Q%d: ",qno++);
                                pfn(query(1,0,s.sz-1,a,b));
                        }


                        //print();
                }

        }














        return 0;
}