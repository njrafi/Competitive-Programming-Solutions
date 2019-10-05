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
#define CASE(a) printf("Case %d:\n",a)

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

map<int,vpi> gg[5];
/// point e add/remove/query
int ans[mxn];


int main()
{

        int t,cs = 1,l,r,q,inp,n;
        sf(t);
        while(t--)
        {
                For(i,5)
                        gg[i].clr;

                vpi rng;
                vi p;
                si eve;

                sff(n,q);
                while(n--)
                {
                        sff(l,r);
                        rng.pb(mp(l,r));


                        int mid = (l+r)/2;

                        /// marking start range
                        gg[1][l].pb(mp(l,r));
                        /// marking mid range
                        gg[2][mid].pb(mp(l,r));
                        /// marking r range
                        gg[3][r].pb(mp(l,r));

                        eve.insert(mid);
                        eve.insert(l);
                        eve.insert(r);
                }

                For(i,q)
                {

                        sf(inp);

                        /// query event
                        gg[4][inp].pb(mp(i,0));

                        p.pb(inp);
                        eve.insert(inp);
                }


//                cout << "yo " << endl;
                /// extreme points
                multiset<int> ext;

                foreach(i,eve)
                {
                        int now = *i;

//                        cout << dbg(now) << endl;
                        For(i,gg[1][now].sz)
                                ext.insert(now);

                        int ansnow = 0;

                        if(ext.sz)
                        {

                                multiset<int>:: iterator it = ext.begin();
                                l = *it;
                                it = ext.end();
                                it--;
                                r = (*it);

                                ansnow = max(now - l,ansnow);
                                ansnow = max(ansnow, r - now);
                        }


//                        cout << now << " " << ansnow << endl;
                        For(i,gg[4][now].sz)
                        {
                                int idx = gg[4][now][i].ff;
//                                cout << now << " " << ansnow << " " << idx << endl;
                                ans[idx] = ansnow;
                        }


                        For(i,gg[2][now].sz)
                        {
                                l = gg[2][now][i].ff;
                                r = gg[2][now][i].ss;
                                ext.erase(ext.find(l));
                                ext.insert(r);

                        }

                        For(i,gg[3][now].sz)
                                ext.erase(ext.find(now));



                }


                CASE(cs++);
                For(i,q)
                        pfn(ans[i]);


        }













        return 0;
}