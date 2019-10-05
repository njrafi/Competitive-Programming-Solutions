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

i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

bool checkbit(int mask,int bit){return mask & (1<<bit);}

int setbit(int mask,int bit){ return mask | (1<<bit) ; }

int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}

i64 now ;
int can[2000][102];
int dp[1200][102];
int lala;
void f(int mask,int prev)
{
        if(prev>100)
                return;
        can[now][prev] = 1;

        if(!mask)
                return;
        if(dp[mask][prev]==lala)
                return;
        dp[mask][prev] = lala;



         For(i,10)
                For(j,10)
                        if(checkbit(mask,i) && checkbit(mask,j))
                        {

                                int nmask = clearbit(mask,i);
                                nmask = clearbit(nmask,j);
                                int nprev;
                                if(!prev)
                                {

                                        if(i!=j)
                                        {
                                                nprev = i*10+j;
                                                f(nmask,nprev);
                                        }
                                        else
                                        {
                                                nprev = i;
                                                f(nmask,nprev);
                                        }
                                }
                                else
                                {
                                        if(i!=j)
                                        {

                                                nprev = prev + i*10 + j;
                                                if(nprev<=100)
                                                        can[now][nprev] = 1;
                                        }
                                        else
                                        {
                                                nprev = prev + i;
                                                if(nprev<=100)
                                                        can[now][nprev] = 1;
                                        }
                                }

                        }

}



void pre()
{
        Fre(i,1,po(2,10))
        {
                i64 sum = 0;
                for(int j = 9 ; j>=0 ; j--)
                        if(checkbit(i,j))
                                sum = sum * 10 + j;
                now = i;
                lala++;
                f(i,0);

        }
}

int main()
{

        pre();
        int t , cs =  1 , n , inp;
        vi v;
        while(1)
        {
                sf(n);
                if(!n)
                        break;
                v.clr;
                while(n--)
                {
                        sf(inp);
                        v.pb(inp);
                }

                vector< pair<i64,i64> > ans;
                For(i,po(2,10))
                {
                        i64 sum = 0;
                        for(int j = 9 ; j>=0 ; j--)
                                if(checkbit(i,j))
                                        sum = sum * 10 + j;
                        bool ok = 1;
                        For(j,v.sz)
                                if(!can[i][v[j]])
                                {
                                        ok = 0;
                                        break;
                                }
                        if(ok)
                                ans.pb(mp(__builtin_popcount(i),sum));


                }
                sort(all(ans));
                CASE(cs++);
                cout << ans[0].ss << endl;
        }












        return 0;
}