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
 
int n,k;
int dp[55][132000];
int dp2[55][20];
int v[55][5],w[20][5];
int lim;
int bac[5];
 
void back_up(int vv)
{
        For(i,4)
                bac[i] = v[vv][i];
}
 
void restore(int vv)
{
        For(i,4)
                v[vv][i] = bac[i];
}
 
int cal_time(int vv,int ww)
{
        if(dp2[vv][ww]!=-1)
                return dp2[vv][ww];
        back_up(vv);
        int ans = 0;
        For(i,3)
        {
                int a = v[vv][i];
                int b = w[ww][i];
                int c = 60;
                if(i==2)
                        c = 24;
              
 
                if(a<=b)
                {
                        if(b-a>a+c-b)
                        {
                                ans += a+c-b;
                                v[vv][i+1]--;
                        }
                        else
                                ans += b-a;
                }
                else
                {
                        if(a-b>b+c-a)
                        {
                                ans += b+c-a;
                                v[vv][i+1]++;
                        }
                        else
                                ans += a-b;
                }
 
        }
 
        restore(vv);
        return dp2[vv][ww] = ans;
}
 
 
 
int f(int pos,int mask)
{
 
        if(mask==lim)
                return 0;
        if(pos==n)
                return inf;
        if(dp[pos][mask]!=-1)
                return dp[pos][mask];
 
        int ans = f(pos+1,mask);
 
        For(i,k)
                if(!checkbit(mask,i))
                {
                        int nmask = setbit(mask,i);
                        ans = min(ans,f(pos+1,nmask) + cal_time(pos,i));
                }
 
        return dp[pos][mask] = ans;
}
 
 
 
int main()
{
 
        int t;
        sf(t);
 
        while(t--)
        {
                sff(n,k);
 
                For(i,n)
                        scanf("%d:%d:%d",&v[i][2],&v[i][1],&v[i][0]);
                For(i,k)
                        scanf("%d:%d:%d",&w[i][2],&w[i][1],&w[i][0]);
 
                lim = (1<<k) - 1;
                mem(dp,-1);
                mem(dp2,-1);
                pfn(f(0,0));
 
        }
 
 
 
 
 
 
 
 
 
 
 
 
 
        return 0;
}
 
