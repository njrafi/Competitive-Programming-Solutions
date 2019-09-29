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
#define WRITE freopen("out1.txt", "w", stdout)
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



bool issquare(i64 num)
{
        i64 sq = sqrt(num);
        sq = max((i64)0,sq-3);
        Fre(i,sq,sq + 6)
        {
                i64 tem = (i64)i * (i64)i;
                if(tem==num)
                        return 1;
        }

        return 0;
}


i64 getsqrt(i64 num)
{
        i64 sq = sqrt(num);
        sq = max((i64)0,sq-3);
        Fre(i,sq,sq + 6)
        {
                i64 tem = (i64)i * (i64)i;
                if(tem==num)
                        return i;
        }
        return 0;

}

int f(i64 B,i64 C,i64 c)
{
        si s;
        i64 D = B*B - 4*C;

        if(D<0)
                return 0;
        if(!issquare(D))
                return 0;
        D = getsqrt(D);
        if((-B+D)%2==0)
        {
                i64 res = (-B+D)/2;
                if(1<=res && res<=c)
                        s.insert(res);
        }
         if((-B-D)%2==0)
        {
                i64 res = (-B-D)/2;
                if(1<=res && res<=c)
                        s.insert(res);
        }

        return s.sz;
}


int main()
{

        i64 q,a,b,c,d;
       // READ;
       // WRITE;
        //int cs = 1;
        cin >> q;
        while(q--)
        {
                cin >> a >> b >> c >> d;
                i64 B = -a;
                int ans = 0;
                Fre(y,1,d+1)
                {
                        i64 C = (i64)y * (i64)y - b * (i64)y;
                        ans += f(B,C,c);
                }
               // CASE(cs++);
                cout << ans << endl;
        }













        return 0;
}

