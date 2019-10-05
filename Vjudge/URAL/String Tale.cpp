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


string s1,s2;

vector<i64> h1,h2,h3,h4,pr1,pr2;

#define mod1 1000000007
#define mod2 1000000009
#define p1 47
#define p2 101


void calc_hash()
{

        h1.pb(0);
        h2.pb(0);
        h3.pb(0);
        h4.pb(0);
        pr1.pb(1);
        pr2.pb(1);

        For(i,s1.sz)
        {
                pr1.pb( (pr1.back()*p1) % mod1   );
                pr2.pb( (pr2.back()*p2) % mod2   );
        }

        For(i,s1.sz)
        {
                h1.pb(  ( (h1.back()*p1) + s1[i] ) % mod1 );
                h2.pb(  ( (h2.back()*p2) + s1[i] ) % mod2 );
                h3.pb(  ( (h3.back()*p1) + s2[i] ) % mod1 );
                h4.pb(  ( (h4.back()*p2) + s2[i] ) % mod2 );
        }

}

bool check(int l1,int r1,int l2,int r2)
{

        i64 hash1 = (h1[r1] - (h1[l1-1] * pr1[r1-l1+1])%mod1 + mod1 ) % mod1;
        i64 hash2 = (h2[r1] - (h2[l1-1] * pr2[r1-l1+1])%mod2 + mod2 ) % mod2;
        i64 hash3 = (h3[r2] - (h3[l2-1] * pr1[r2-l2+1])%mod1 + mod1 ) % mod1;
        i64 hash4 = (h4[r2] - (h4[l2-1] * pr2[r2-l2+1])%mod2 + mod2 ) % mod2;

        //cout << hash1 << " " << hash2 << " " << hash3 << " " << hash4 << endl;
        if(hash1==hash3 && hash2==hash4)
                return 1;

        return 0;

}


int main()
{

        int n;
        sf(n);
        cin >> s1 >> s2;
        if(s1==s2)
        {
                cout << 0 << endl;
                return 0;
        }
        calc_hash();

        Fre(i,1,s1.sz)
        {
               // cout << 1 << " " << s1.sz-i << " " << i+1 << " " << s1.sz << endl;
                //cout << s1.sz-i+1 << " " << s1.sz << " " << 1 << " " << i << endl;
                if(check(1,s1.sz-i,i+1,s1.sz) && check(s1.sz-i+1,s1.sz,1,i))
                {
                        cout << i << endl;
                        return 0;
                }
        }

        cout << -1 << endl;










        return 0;
}