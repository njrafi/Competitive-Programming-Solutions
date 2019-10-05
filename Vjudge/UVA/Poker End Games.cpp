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




vector < vector<double> > co;            // contains the coeff,ans included
/// last col e constant


vector<double>  ans;

/// returns solution (0,1 or inf)

int gauss()
{
        int n = (int) co.size();         // row size
        int m = (int) co[0].size() - 1;  // col size

        vector<int> where (m, -1);          // where[i] = -1 , row i zero, var i independent
        for (int col=0, row=0; col<m && row<n; ++col)
        {
                int sel = row;
                Fre(i,row,n)
                        if (abs (co[i][col]) > abs (co[sel][col]))
                                sel = i;
                if (abs (co[sel][col]) < eps)
                        continue;
                Fre(i,col,m+1)
                        swap (co[sel][i], co[row][i]);
                where[col] = row;

                For(i,n)
                        if (i != row)
                        {
                                double c = co[i][col] / co[row][col];
                                        Fre(j,col,m+1)
                                                co[i][j] -= co[row][j] * c;
                        }
                row++;
        }

        ans.assign (m, 0);
        For(i,m)
                if (where[i] != -1)
                        ans[i] = co[where[i]][m] / co[where[i]][i];


        /// checking
        For(i,n)
        {
                double sum = 0;
                For(j,m)
                    sum += ans[j] * co[i][j];
                if (abs (sum - co[i][m]) > eps)
                    return 0;
        }

        For(i,m)
                if (where[i] == -1)
                        return inf;
        return 1;
}


map<pii,int> id;

bool vis[400][400];
int now;

void f(int a,int b)
{
        if(vis[a][b])
                return;
         vis[a][b] = 1;


        id[mp(a,b)] = now++;
//        cout << a << " " << b << " " << now << endl;
        if(!a && !b)
                return;
        int mn = min(a,b);
        f(a+mn,b-mn);
        f(a-mn,b+mn);
}

double calc1(int a,int b)
{
        co.clr;
//         cout << "start" << endl;
        foreach(i,id)
        {
                vector<double> tem;
                For(j,now+1)
                        tem.pb(0);

                int a = (i->ff).ff;
                int b = (i->ff).ss;

                tem[id[mp(a,b)]] = 1;
//                cout << id[mp(a,b)] << endl;
                int mn = min(a,b);
//                cout << a << " " << b << endl;
                if(!a )
                {


//              cout << "gg " << 0 << endl;
                }
                else if(!b)
                {

                        tem.back() = 1;
//                        cout << "gg " << 1 << endl;
                }
                else
                {
                        tem[id[mp(a+mn,b-mn)]] = -0.5;
                        tem[id[mp(a-mn,b+mn)]] = -0.5;

//                        cout << id[mp(a-mn,b+mn)] << endl;
//                        cout << id[mp(a+mn,b-mn)] << endl;
//                        cout << a+mn << " " << b-mn << endl;
//                        cout << a-mn << " " << b+mn << endl;
                }

                co.pb(tem);
//                cout << endl << endl;
        }


//        cout << "yo" << endl;
        gauss() ;

        return ans[id[mp(a,b)]];
}


double calc(int a,int b)
{
        co.clr;
//         cout << "start" << endl;
        foreach(i,id)
        {
                vector<double> tem;
                For(j,now+1)
                        tem.pb(0);

                int a = (i->ff).ff;
                int b = (i->ff).ss;

                tem[id[mp(a,b)]] = 1;
                int mn = min(a,b);

                if(a && b)
                {
                        tem[id[mp(a+mn,b-mn)]] = -0.5;
                        tem[id[mp(a-mn,b+mn)]] = -0.5;
                        tem.back() = 1;
//                        cout << id[mp(a-mn,b+mn)] << endl;
//                        cout << id[mp(a+mn,b-mn)] << endl;
//                        cout << a+mn << " " << b-mn << endl;
//                        cout << a-mn << " " << b+mn << endl;
                }

                co.pb(tem);
//                cout << endl << endl;
        }


//        cout << "yo" << endl;
        gauss();

        return ans[id[mp(a,b)]];
}

int main()
{

        int t,a,b,cs = 1;
        sf(t);

        while(t--)
        {
                sff(a,b);

                id.clr;
                mem(vis,0);
                now = 0;

                f(a,b);


                CASE(cs++);
                cout << fixed << setprecision(6) << calc(a,b) << " " << calc1(a,b) << endl;
        }













        return 0;
}