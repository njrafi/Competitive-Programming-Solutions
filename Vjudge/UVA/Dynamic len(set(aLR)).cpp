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

#define mxn 100005



struct queries
{
        int l,r,t,id;
        // left,right,time,index
        queries(){}
        queries(int ll,int rr,int tt,int idx)
        {
                l = ll;
                r = rr;
                t = tt;
                id = idx;
        }
};

struct updates
{
        int id,pre,now;
        // index,prev value,new value

        updates(){}
        updates(int idx,int xpre,int xnow)
        {
                id = idx;
                pre = xpre;
                now = xnow;
        }
};



int arr[mxn];   // original array
int last[mxn];  // last state before update
vector<queries> Q;      // to store queries
vector<updates> U;      // to store updates
i64 ans[mxn];           // last ans;
int L,R,T,cnt[1000006];     // pointers and count
// remember cnt array size is not mxn ;)

int sum;                // current ans
int blockSize;          //

bool cmp(queries a,queries b)
{
        int l1 = a.l/blockSize;
        int l2 = b.l/blockSize;
        int r1 = a.r/blockSize;
        int r2 = b.r/blockSize;
        if(l1 != l2) return l1 < l2;
        if(r1 != r2) return r1 < r2;

        return a.t<b.t;
}


void add(int id)
{
        cnt[arr[id]]++;
        if(cnt[arr[id]] == 1)
                sum++;
}


void rem(int id)
{
        cnt[arr[id]]--;
        if(cnt[arr[id]] == 0)
                sum--;
}

void apply(int id,int val)
{
        if(L<=id && id<=R) rem(id);
        arr[id] = val;
        if(L<=id && id<=R) add(id);
}

int get_ans()
{
        return sum;
}


void mo_with_update()
{
        sort(all(Q),cmp);
        mem(cnt,0);

        L = 0 , R = - 1 , sum = 0, T = 0;

        For(i,Q.sz)
        {
                while(T < Q[i].t)
                {
                        T++;
                        apply(U[T].id,U[T].now);
                }

                while(T > Q[i].t)
                {
                        apply(U[T].id , U[T].pre);
                        T--;
                }

                while(L > Q[i].l) add(--L);

                while(R < Q[i].r) add(++R);

                while(L < Q[i].l) rem(L++);

                while(R > Q[i].r) rem(R--);

                ans[Q[i].id] = get_ans();
        }
}



void process_input(int q)
{

        Q.clr;
        U.clr;
        U.pb( updates(0,0,0) );

        int l,r;
        char op[3];

        For(i,q)
        {
                scanf("%s",op);
                if(op[0]=='Q')
                {
                        sff(l,r);
                        r--;
                        Q.pb( queries(l,r,(int)U.sz - 1,(int)Q.sz) );
                }
                else
                {
                        sff(l,r);
                        U.pb( updates(l,last[l],r));
                        last[l] = r;
                }
        }
        mo_with_update();
}


int main()
{


        int n,q;
        sff(n,q);


        blockSize = 2160;
        For(i,n)
        {
                sf(arr[i]);
                last[i] = arr[i];
        }

        process_input(q);


        For(i,Q.sz)
                pfn(ans[i]);







        return 0;
}