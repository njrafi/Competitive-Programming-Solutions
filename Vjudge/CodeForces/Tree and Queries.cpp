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



#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree< pii ,null_type,less< pii >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


#define mxn 100005

int ssz[mxn];
vi g[mxn];
ordered_set s;

/// Getting subtree size
void getsz(int v, int p)
{
 ssz[v] = 1;

 for(auto u : g[v])
  if(u != p)
  {
   getsz(u, v);
   ssz[v] += ssz[u];
  }
}

/// Vector pointer
vi *vec[mxn];


int col[mxn];
int cnt[mxn];
int ans[mxn];
vpi qq[mxn];
int gg;

void ans_query(int v)
{
        For(i,qq[v].sz)
        {
                int k = qq[v][i].ff;
                int idx = qq[v][i].ss;

                ans[idx] = s.sz - s.order_of_key(mp(k,0));
        }
}

void rem(int val)
{
        if(val)
                s.erase(s.upper_bound(mp(val,0)));
}

void dfs(int v, int p, bool keep)
{
 int mx = -1, bigChild = -1;
 for(auto u : g[v])
  if(u != p && ssz[u] > mx)
                {
   mx = ssz[u];
                        bigChild = u;
                }

 for(auto u : g[v])
  if(u != p && u != bigChild)
   dfs(u, v, 0);

 if(bigChild != -1)
 {

  dfs(bigChild, v, 1);
  vec[v] = vec[bigChild];
 }
 else
  vec[v] = new vi();

 vec[v]->push_back(v);

        rem(cnt[col[v]]);
 cnt[col[v]]++;
 s.insert(mp(cnt[col[v]],gg++));

 for(auto u : g[v])
  if(u != p && u != bigChild)
   for(auto x : *vec[u])
   {

    rem(cnt[col[x]]);
                                cnt[col[x]]++;
                                s.insert(mp(cnt[col[x]],gg++));
    vec[v] -> push_back(x);
   }

        ans_query(v);

 if(keep == 0)
  for(auto u : *vec[v])
                {
                        rem(cnt[col[u]]);
                        cnt[col[u]]--;
                        if(cnt[col[u]])
                                s.insert(mp(cnt[col[u]],gg++));
                }
}


int main()
{

        int n,m,u,v;
        gg = 1;

        sff(n,m);

        Fre(i,1,n+1)
                sf(col[i]);


        For(i,n-1)
        {
                sff(u,v);
                g[u].pb(v);
                g[v].pb(u);
        }


        For(i,m)
        {
                sff(u,v);
                qq[u].pb(mp(v,i));
        }


        getsz(1,-1);
        dfs(1,-1,1);

        For(i,m)
        {
                pfn(ans[i]);
        }



        return 0;
}