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
#define READ freopen("test.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)

int dx[] = {0,1,0,-1,1,2,0,0};
int dy[] = {1,0,-1,0,3,3,2,1};


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


vs v,w;
string s;
vpi a[4];

map<string,bool> ans;

string tostr()
{
        string tem;
        For(i,4)
        {
                tem += a[i][0].ff+'0';
                tem += a[i][0].ss+'0';
        }
        return tem;

}

void print()
{
        w = v;
        For(j,4)
                For(i,a[j].sz)
                        w[a[j][i].ff][a[j][i].ss] = 'A'+j;
}

void calcpos(string tem)
{
        mem(a,NULL);

        For(i,4)
        {

                a[i].pb(mp(tem[2*i]-'0',tem[2*i+1]-'0'));
                a[i].pb(mp(a[i][0].ff,a[i][0].ss+1));
                a[i].pb(mp(a[i][0].ff+1,a[i][0].ss));
                a[i].pb(mp(a[i][0].ff+1,a[i][0].ss+1));

        }
}


bool valid(pii p)
{
        if(p.ff>=0 && p.ff<8 && p.ss>=0 && p.ss<8 && w[p.ff][p.ss]=='.' )
                return 1;
        return 0;
}



void go(int dir,int l,int r)
{
        For(k,4)
        {

                For(j,4)
                {

                        pii a0 = a[j][l] , a1 = a[j][r];
                        print();
                        while(1)
                        {
                                a0.ff += dx[dir];
                                a0.ss += dy[dir];
                                a1.ff += dx[dir];
                                a1.ss += dy[dir];
                                if(valid(a0) && valid(a1))
                                {
                                        For(i,a[j].sz)
                                        {

                                                a[j][i].ff += dx[dir];
                                                a[j][i].ss += dy[dir];
                                        }
                                }
                                else
                                        break;
                        }
                }
        }
}


int lala;

void dfs(string gg)
{

        if(ans.find(gg)!=ans.end())
                return;
        if(lala)
                ans[gg] = 1;
        lala++;
        For(i,4)
        {
                calcpos(gg);
                go(i,dx[i+4],dy[i+4]);
                dfs(tostr());
        }
}


int main()
{

        int t,cs=1;
        sf(t);
        while(t--)
        {
                v.clr;
                mem(a,NULL);
                ans.clr;
                lala = 0;
                For(i,8)
                {
                        cin >> s;
                        v.pb(s);
                }

                For(i,v.sz)
                        For(j,v[0].sz)
                                if(v[i][j]>='A' && v[i][j]<='D')
                                {
                                        a[v[i][j]-'A'].pb(mp(i,j));
                                        v[i][j] = '.';
                                }

                dfs(tostr());
                CASE(cs++);
                cout << ans.sz << endl;
        }

        return 0;
}