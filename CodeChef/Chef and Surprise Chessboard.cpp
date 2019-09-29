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


#define mxn 205

vs v;
string s;
int n,m;
int a[205][205] , b[205][205];
int cum[2][205][205];
int ghor[3];
int ans[205];


int f(int x1,int y1,int x2,int y2,int idx)
{

        return cum[idx][x2][y2] - cum[idx][x2][y1-1] - cum[idx][x1-1][y2] + cum[idx][x1-1][y1-1];
}

void pre()
{
        Fre(i,1,n+1)
                Fre(j,1,m+1)
                        if( (i+j) % 2)
                                a[i][j] = v[i-1][j-1] - '0';
                        else
                                b[i][j] = v[i-1][j-1] - '0';

        Fre(i,1,n+2)
                Fre(j,1,m+1)
                {
                        cum[0][i][j] = cum[0][i][j-1] + a[i][j];
                        cum[1][i][j] = cum[1][i][j-1] + b[i][j];
                }

        Fre(i,1,n+2)
                Fre(j,1,m+2)
                {

                        cum[0][i][j] += cum[0][i-1][j];
                        cum[1][i][j] += cum[1][i-1][j];
                }

//        Fre(i,1,n+1)
//        {
//                Fre(j,1,m+1)
//                        cout << a[i][j] << " ";
//                cout << endl;
//        }
//
//        cout << endl << endl;
//        Fre(i,1,n+1)
//        {
//                Fre(j,1,m+1)
//                        cout << b[i][j] << " ";
//                cout << endl;
//        }

        For(i,205)
                ans[i] = inf;

        Fre(x1,1,n+1)
                Fre(y1,1,m+1)
                        Fre(k,1,202)
                        {
                                int x2 = x1 + k - 1;
                                int y2 = y1 + k - 1;

                                if(x2 > n || y2 > m)
                                        continue;

                                ghor[0] = ghor[1] = (k*k) / 2;
                                if(k%2)
                                        ghor[ 1 - ( (x1+y1) % 2) ]++;


                                int zeroOne = f(x1,y1,x2,y2,0) + ghor[1] - f(x1,y1,x2,y2,1);
                                int oneZero = ghor[0] - f(x1,y1,x2,y2,0)  + f(x1,y1,x2,y2,1);


//                                cout << f(x1,y1,x2,y2,0) << " " << f(x1,y1,x2,y2,1) << endl;
//                                cout << ghor[0] << " " << ghor[1] << endl;
//                                cout << x1 << " " << y1 << " " << k << " " << zeroOne << " " << oneZero << endl;
//                                cout << (x1+y1) % 2 << endl;
//                                cout << endl;

                                int ansHere = min(zeroOne,oneZero);

//                                cout << x1 << " " << y1 << " " << k << " " << ansHere << endl;

                                ans[ k ] = min( ans[k] , ansHere );

                        }

        for(int i = 203 ; i>=0 ; i--)
                ans[i] = min(ans[i] , ans[i+1]);

//        For(i,n*m)
//                cout << i << " " << ans[i] << endl;



}

int main()
{

        cin >> n >> m;

        For(i,n)
        {
                cin >> s;
                v.pb(s);
        }

        pre();


//        int x1,y1,x2,y2;
//        while(cin >> x1 >> y1 >> x2 >> y2)
//        {
//                cout << f(x1,y1,x2,y2,0) << endl;
//                cout << f(x1,y1,x2,y2,1) << endl;
//
//        }


        int q,inp;
        sf(q);
        while(q--)
        {
                sf(inp);

                int lo = 1 , hi = 203 , ret = 0;
                while(lo<=hi)
                {
                        int mid = (lo+hi)/2;
                        if(ans[mid]<=inp)
                        {
                                ret = mid;
                                lo = mid + 1;
                        }
                        else
                                hi = mid - 1;
                }

                pfn(ret);
        }








        return 0;
}


