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
#define inf 536870911
#define infll 12345678901234567
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(i64 i = a; i < b; i++)
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

//int setbit(int mask,int bit){return mask   (1<<bit);}

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}

#define lim 1000006

bool isp[lim];
vector<i64> primes;
vector< pair<i64,i64> > pref[100005];
i64 a,b,lat[100005];

void sieve()
{
        int up = sqrt(lim);


        Fre(i,2,up)
                if(!isp[i])
                        for( int j = i * i ; j < lim ; j += i)
                                isp[j] = 1;

        Fre(i,2,lim)
                if(!isp[i])
                        primes.pb(i);
}




void sieve2()
{

        Fre(i,a,b+1)
                lat[i-a] = i;
        for(int i = 0 ; primes[i]*primes[i]<=b ; i++)
        {
                i64 gg = a/primes[i];
                while(gg*primes[i]<a)
                        gg++;

                for(i64 j = gg * primes[i] ; j<=b ; j+= primes[i])
                {

                        pref[j-a].pb(mp(primes[i],0));

                        while(lat[j-a] % primes[i]==0)
                        {
                                lat[j-a] /= primes[i];
                                pref[j-a].back().ss++;
                        }
                }

        }

        Fre(i,a,b+1)
                if(lat[i-a]>1)
                        pref[i-a].pb(mp(lat[i-a],1));
}

int main()
{


        cin >> a >> b;
        sieve();
        sieve2();


        i64 ans = 0;
        for(i64 i = a ; i <= b ; i++)
        {
                priority_queue<int> p;
                i64 gun = 1;
              //  cout << i << " = ";
                For(j,pref[i-a].sz)
                {

                        gun *= pref[i-a][j].ss+1;
                        p.push(pref[i-a][j].ss+1);
                        //cout << pref[i-a][j].ss << " ";
                }

              //  cout << endl;

                while(!p.empty() && p.top()!=1)
                {
                        int tem = p.top();
                        ans += gun;
                        gun = gun*(tem-1)/tem;
                        tem--;
                        p.pop();
                        p.push(tem);
                }

              //   cout << ans << endl;
        }

        cout << ans << endl;










        return 0;
}

