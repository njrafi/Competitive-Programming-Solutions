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
#define READ freopen("car.in", "r", stdin)
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

#define mxn 500005

int ans[mxn],fuel[mxn],p[mxn][22],lvl[mxn];
vpi v[mxn];
int n;
i64 dis[mxn][22]; // 2^jth parent distance
int gg[mxn];    // the update array

void dfs(int now,int par,int pedge,int l)
{

//        cout << now << endl;
        p[now][0] = par;
        dis[now][0] = pedge;
        lvl[now] = l;

        For(i,v[now].sz)
        {
                int vv = v[now][i].ff;
                int ww = v[now][i].ss;

                if(vv==par) continue;
                dfs(vv,now,ww,l+1);
        }
}

void pre()
{
        mem(p,-1);
        mem(gg,0);

        dfs(1,-1,inf,0);

        Fre(j,1,22)
                Fre(i,1,n+1)
                        if(p[i][j-1]!=-1)
                        {
                                /// (j-1)th parent
                                int tem = p[i][j-1];
                                p[i][j] = p[ tem ][ j - 1];
                                dis[i][j] = dis[i][j-1] + dis[tem][j-1];
                        }
}

/// gives jth parent and jth parent distance
pair<int,i64> f(int u,int j)
{
        i64 ans = 0;
        for(int i = 20 ; i >= 0 ; i--)
                if(p[u][i]!=-1 && (1<<i)<=j)
                {
                        ans += dis[u][i];
                        j -= (1<<i);
                        u = p[u][i];
                }



        return mp(u,ans);
//        cout << u << " " << ans << endl;
}

int dfs2(int node,int par = -1)
{
        int ansnow = 0;

        For(i,v[node].sz)
        {
                int vv = v[node][i].ff;
                if(vv==par)continue;


                ansnow += dfs2(vv,node);
        }

        ans[node] = ansnow;

        return ansnow + gg[node];
}

int main()
{

        READ;
        int t,a,b,c;
        sf(t);
        while(t--)
        {

                mem(v,NULL);

                sf(n);
                Fre(i,1,n+1)
                        sf(fuel[i]);

                For(i,n-1)
                {
                        sfff(a,b,c);
                        v[a].pb(mp(b,c));
                        v[b].pb(mp(a,c));
                }
                pre();


                Fre(i,1,n+1)
                {
                        int lo = 0 , hi = lvl[i] , ansnow;

                        while(lo<=hi)
                        {
                                int mid = (lo+hi)/2;


                                pair<int,i64> tem = f(i,mid);

                                if(tem.ss<=fuel[i])
                                {
                                        ansnow = tem.ff;
                                        lo = mid + 1;
                                }
                                else
                                        hi = mid - 1;
                        }

                        gg[i]++;
                        gg[ansnow]--;
//                        cout << i << " " << ansnow << endl;
                }



                dfs2(1,0);


                Fre(i,1,n+1)
                        pfs(ans[i]);

                puts("");
        }














        return 0;
}