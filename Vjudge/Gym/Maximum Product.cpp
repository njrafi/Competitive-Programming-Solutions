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



vi vhi , vlo;
int dig[30][3][3][3];
bool eqlogg[30][3][3][3],eqhigg[30][3][3][3];
bool okgg[30][3][3][3];

i64 dp[30][3][3][3];

void conv(i64 lo,i64 hi)
{
        vlo.clr;
        vhi.clr;

        while(hi)
        {
                vhi.pb(hi%10);
                hi /= 10;
        }

        reverse(all(vhi));

        while(lo)
        {
                vlo.pb(lo%10);
                lo /= 10;
        }

        while(vlo.sz!=vhi.sz)
                vlo.pb(0);

        reverse(all(vlo));

//
//        For(i,vlo.sz)
//                cout << vlo[i] << " ";
//
//
//        cout << endl;
//
//        For(i,vhi.sz)
//                cout << vhi[i] << " ";
//        cout << endl;
}

i64 f(int pos,bool eqlo,bool eqhi,bool ok)
{
        if(pos==vhi.sz)
                return 1;
        if(dp[pos][eqlo][eqhi][ok]!=-1)
                return dp[pos][eqlo][eqhi][ok];

        int lo = 0 , hi = 9;

        if(eqlo)
                lo = vlo[pos];
        if(eqhi)
                hi = vhi[pos];

        i64 ans = 0;
        Fre(i,lo,hi+1)
        {

                i64 gun = i;
                if(!gun && !ok)
                        gun = 1;

                i64 tem = gun * f(pos+1, eqlo && (i==vlo[pos]) , eqhi && (i==vhi[pos]), ok || i);

                if(tem>=ans)
                {
                        ans = tem;
                        dig[pos][eqlo][eqhi][ok] = i;
                        eqlogg[pos][eqlo][eqhi][ok] = eqlo && (i==vlo[pos]);
                        eqhigg[pos][eqlo][eqhi][ok] = eqhi && (i==vhi[pos]);
                        okgg[pos][eqlo][eqhi][ok] = ok || i;
                }
        }
        return dp[pos][eqlo][eqhi][ok] = ans;
}


i64 last;

void get_num(int pos,bool eqlo,bool eqhi,bool ok)
{
        if(pos==vhi.sz)
                return;

//        cout << "gg " << pos << endl;
//        cout << dig[pos][eqlo][eqhi] << endl;
        last *= 10;
        last += dig[pos][eqlo][eqhi][ok];

        get_num(pos+1,eqlogg[pos][eqlo][eqhi][ok],eqhigg[pos][eqlo][eqhi][ok],okgg[pos][eqlo][eqhi][ok]);
}

int main()
{

        i64 lo,hi;
        while(cin >> lo >> hi)
        {

                conv(lo,hi);
                mem(dp,-1);
                f(0,1,1,0);
                last = 0;

//                For(i,vlo.sz)
//                        cout << dig[i] ;
//                cout << endl;

                get_num(0,1,1,0);

                cout << last << endl;
        }













        return 0;
}