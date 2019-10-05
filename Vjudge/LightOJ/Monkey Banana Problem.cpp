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
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt","w",stdout)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)
 
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//i64 dp[60][60];
 
 
//functions
 
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
 
void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
 
void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
 
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
 
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
 
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
 
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
 
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
 
vi bnd;
int ind[205][205],dp[205][205],n;
 
int call(int i,int j)
{
        if(j<1 || j>bnd[i])
                return 0;
        if(i==2*n-1)
                return ind[i][j];
        if(dp[i][j]!=-1)
                return dp[i][j];
        if(i<n)
                return dp[i][j] = max(call(i+1,j),call(i+1,j+1)) + ind[i][j];
        else
                return dp[i][j] = max(call(i+1,j),call(i+1,j-1)) + ind[i][j];
}
 
 
 
int main()
{
        int t,c=1,i;
        fastRead(&t);
        while(t--)
        {
                fastRead(&n);
                bnd.clr;
                bnd.pb(0);
                mem(dp,-1);
                for(i=1;i<=n;i++)
                {
                        bnd.pb(i);
                        for(int j=1;j<=i;j++)
                                fastRead(&ind[i][j]);
                }
                for(;i<2*n;i++)
                {
                        bnd.pb(2*n-i);
                        for(int j=1;j<=2*n-i;j++)
                                fastRead(&ind[i][j]);
                }
                CASE(c++);
                fastWrite(call(1,1));
 
        }
 
 
 
 
 
 
 
 
 
        return 0;
}