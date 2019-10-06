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
#define vll vector<i64>
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
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
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
 
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
 
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
 
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
 
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
 
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
 
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
 
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
 
vi v;
int tree[400005];
 
void build(int i,int s,int e)
{
        if(s==e)
                tree[i] = v[s];
        else
        {
                int mid = (s+e)/2;
                build(2*i,s,mid);
                build(2*i+1,mid+1,e);
                tree[i] = tree[i*2] + tree[i*2+1];
        }
}
 
void update(int i,int s,int e,int idx,int val)
{
        if(s==e)
        {
                tree[i] = val;
                v[idx] = val;
        }
        else
        {
                int mid = (s+e)/2;
                if(idx<=mid)
                        update(2*i,s,mid,idx,val);
                else
                        update(i*2+1,mid+1,e,idx,val);
                tree[i] = tree[2*i] + tree[2*i+1];
        }
 
}
 
int query(int i,int s,int e,int l ,int r)
{
        if(r<s || e<l)
                return 0;
        if(l<=s && e<=r)
                return tree[i];
        int mid = (s+e)/2;
        int p1 = query(2*i,s,mid,l,r);
        int p2 = query(2*i+1,mid+1,e,l,r);
        return (p1+p2);
}
 
 
int main()
{
 
        //ios_base::sync_with_stdio(false);cin.tie(0);
        int n,q,inp,l,r;
        sf(n);
        v.pb(0);
        For(i,n)
        {
                sf(inp);
                if(inp%2)
                        inp = 0;
                else
                        inp = 1;
                v.pb(inp);
        }
        build(1,1,n);
        sf(q);
        while(q--)
        {
                sfff(inp,l,r);
                if(!inp)
                {
                        if(r%2)
                                r = 0;
                        else
                                r = 1;
                        update(1,1,n,l,r);
                }
                else if(inp==1)
                        cout << query(1,1,n,l,r) << endl;
                else
                        cout << r-l+1-query(1,1,n,l,r) << endl;
 
        }
        return 0;
}
 
