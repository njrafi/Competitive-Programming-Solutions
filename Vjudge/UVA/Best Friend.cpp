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
#define CASE(a) printf("Case %d\n",a)

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

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}


#define mxn 2000006
vector<i64> primes;
bool ispr[mxn];


void sieve()
{
        int lim = sqrt(mxn) + 2;

        Fre(i,2,lim)
                for(int j = i * i ; j < mxn ; j += i)
                        ispr[j] = 1;

        Fre(i,2,mxn)
                if(!ispr[i])
                        primes.pb(i);

//        For(i,100)
//                pfs(v[i]);
//        puts("");

//        cout << primes.sz << endl;
}


vector<i64> factors(i64 n)
{
        vector<i64> v;
        for(int i = 0 ; primes[i] * primes[i] <= n ; i++  )
                if( n % primes[i] == 0)
                {
                        v.pb(primes[i]);
                        while( n % primes[i] == 0 )
                                n /= primes[i];
                }

        if(n > 1)
                v.pb(n);

        return v;
}


vector<i64> divisors(i64 n)
{
        vector<i64> v;

        v.clr;
        int tem = sqrt(n);
        Fre(i,1,tem+1)
                if(n%i==0)
                {
                        v.pb(i);
                        if(n/i!=i)
                                v.pb(n/i);
                }

        return v;
}

i64 phi(i64 n,vector<i64> v)
{
        i64 ans = n;
        i64 lim = sqrt(n)+2;
        /// v[i] is primes

        for(int i=0;i<v.sz && v[i]<lim;i++)
                if(n%v[i]==0)
                {
//                        cout << v[i] <<endl;
                        ans = ( ans * (v[i]-1)) /v[i];
//                        cout << ans << endl;
                        while(n%v[i]==0)
                                n /= v[i];
                }

        if(n>1)
                ans = ans/n*(n-1);

        return ans;
}

//int val[mxn];
vector< pair<i64,i64> > cum;

int main()
{
        sieve();
        int t,q,cs = 1;
        i64 n,x;
        sf(t);
        while(t--)
        {
                scanf("%lld", &n);
                sf(q);

                vector<i64> v = factors(n);

                vector<i64> dd = divisors(n);
//                cout << v.sz << endl;
//
//                mem(val,0);
//
//                Fre(i,1,n+1)
//                {
////                        cout << "Gcd " << i << " " << n << " " << __gcd((i64)i,n) <<endl;
//                        val[ __gcd((i64)i,n) ]++;
//                }
                cum.clr;

//                cum.pb(-infll,0);

                For(i,dd.sz)
                {
                        i64 gg = dd[i];


//                        cout << n << " " << gg << " " << phi(n/gg,v) << " " << val[gg] << endl;
                        cum.pb( {gg , phi(n/gg,v)});

//                        cout << gg << " " << phi(n/gg,v) << endl;
                }

                cum.pb({-infll,0});

                sort(all(cum));

                Fre(i,1,cum.sz)
                        cum[i].ss += cum[i-1].ss;


                CASE(cs++);
                while(q--)
                {
                        scanf("%lld",&x);

                        int lo = 0 , hi = cum.sz - 1;
                        i64 ans = 0;

                        while(lo<=hi)
                        {
                                int mid = (lo+hi)/2;
                                if(cum[mid].ff <= x)
                                {
                                        ans = cum[mid].ss;
                                        lo = mid + 1;
                                }
                                else
                                        hi = mid - 1;
                        }

                        printf("%lld\n",ans);
                }

        }















        return 0;
}