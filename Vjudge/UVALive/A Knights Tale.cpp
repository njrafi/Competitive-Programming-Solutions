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

bool checkbit(int mask,int bit){return mask & (1<<bit);}

int setbit(int mask,int bit){ return mask | (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}



i64 knight_move(pair<i64,i64> p)
{
        i64 x = p.ff , y = p.ss , a,b,z,c,d;
        x = abs(x);
        y = abs(y);
        if(x<y)
                swap(x,y);

        if(x==2 && y==2)
                return 4;
        if(x==1 && y==0)
                return 3;

        if(!y || (y<<1) < x)
        {
                c = y & 1;
                a = x - ( c << 1);
                b = a & 3;
                return ( (a-b)>>1) + b + c;
        }
        else
        {
                d = x - ( (x-y) >> 1);
                z = ( ( d % 3) != 0);
                c = (x - y) & 1;
                return ( (d/3) * 2) + c + (z * 2 * (1-c));
        }
}

i64 get_dis(pair<i64,i64> p1,pair<i64,i64> p2)
{
        if(p1.ff>p2.ff)
                swap(p1,p2);
        if(p1.ss>p2.ss)
                p2.ss = 2*p1.ss - p2.ss;

        p2.ff -= p1.ff;
        p2.ss -= p1.ss;

        return knight_move(p2);
}

vector< pair<i64,i64> >  v,w;

i64 dp[20][400000];
int vis[20][400000];
int cs;

i64 f(int pos,int mask)
{
        if(pos==v.sz)
                return 0;
        if(vis[pos][mask]==cs)
                return dp[pos][mask];
        vis[pos][mask] = cs;
        i64 ans = infll;

        For(i,w.sz)
                if(!checkbit(mask,i))
                {
                        i64 dis = get_dis(v[pos],w[i]);
//                        cout << dis << endl;
                        int nmask = setbit(mask,i);

                        ans = min(ans, dis + f(pos+1,nmask));
                }
        return dp[pos][mask] = ans;
}


int main()
{

        int n;
        i64 a,b;
        while(1)
        {
                v.clr;
                w.clr;
                sf(n);

                if(!n)
                        break;
                For(i,n)
                {
                        cin >> a >> b;
                        v.pb(mp(a,b));
                }

                For(j,n)
                {
                        cin >> a >> b;
                        w.pb(mp(a,b));
                }
                cs++;

                cout << cs << ". ";
                cout << f(0,0) << endl;

        }













        return 0;
}