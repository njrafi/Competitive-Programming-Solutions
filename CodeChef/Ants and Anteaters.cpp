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

vs v;
int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,-1,1};


bool invalid[55][55];

int main()
{
//        WRITE;
        int t,n,m;
        string s;
        sf(t);

        mpi gg;
        gg['R'] = 0;
        gg['D'] = 1;
        gg['L'] = 2;
        gg['U'] = 3;

        while(t--)
        {
                sff(n,m);
                v.clr;
                while(n--)
                {
                        cin >> s;
                        v.pb(s);
                }

                vpi pos;
                vi dir;
                mem(invalid,0);

                For(i,v.sz)
                        For(j,v[0].sz)
                                if(v[i][j] == '#')
                                        invalid[i][j] = 1;
                                else if( v[i][j] != '-')
                                {
                                        pos.pb({i,j});
                                        dir.pb(gg[v[i][j]]);
                                }

                set<pii> ans;
                For(i,55)
                {
                        map<pii,vi> lala;
                        For(j,pos.sz)
                        {
                                pos[j].ff += dx[dir[j]];
                                pos[j].ss += dy[dir[j]];
                                int x = pos[j].ff;
                                int y = pos[j].ss;
                                if(x >= 0 && y >=0 && x < v.sz && y < v[0].sz && !invalid[x][y] )
                                        lala[{x,y}].pb(j);
                                else {
                                        pos[j].ff = inf;
                                        pos[j].ss = inf;
                                }
                        }

                        for(auto j : lala)
                        {
                                vi mil = j.ss;
                                For(k,mil.sz)
                                        Fre(l,k+1,mil.sz)
                                                if(mil[l] != mil[k])
                                                {
//                                                        cout << j.ff.ff << " " << j.ff.ss << " " << mil[l] << " " << mil[k] << endl;
                                                        ans.insert( { min(mil[l],mil[k]) , max(mil[l],mil[k]) } );
                                                }
                        }
                }

                pfn(ans.sz);
        }













        return 0;
}


