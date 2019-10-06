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
 
 
#define mxn 1000006
 
#define p1 33
#define p2 163
 
 
unsigned i64 pr1[mxn],pr2[mxn],h1[mxn],h2[mxn],uh1[mxn],uh2[mxn];
string s,us;
 
 
void prime_calc()
{
        pr1[0] = 1;
        pr2[0] = 1;
 
        Fre(i,1,mxn)
        {
                pr1[i] = p1 * pr1[i-1];
                pr2[i] = p2 * pr2[i-1];
        }
}
 
void hash_calc()
{
        h1[0] = h2[0] = uh1[0] = uh2[0]  = 0;
        us = s;
        reverse(all(us));
 
        For(i,s.sz)
        {
                h1[i+1] = h1[i] * p1 + s[i];
                h2[i+1] = h2[i] * p2 + s[i];
                uh1[i+1] = uh1[i] * p1 + us[i];
                uh2[i+1] = uh2[i] * p2 + us[i];
        }
}
 
void print(string s,int l,int r)
{
        Fre(i,l,r+1)
                cout << s[i];
        cout << endl;
}
 
bool ispalin(int l,int r)
{
        int rr = s.sz - l - 1 ;
        int ll = s.sz - r - 1;
        int len = r - l + 1;
 
//        print(s,l,r);
//        print(us,ll,rr);
 
        unsigned s1 = h1[r+1] - h1[l] * pr1[len];
        unsigned s2 = h2[r+1] - h2[l] * pr2[len];
        unsigned u1 = uh1[rr+1] - uh1[ll] * pr1[len];
        unsigned u2 = uh2[rr+1] - uh2[ll] * pr2[len];
 
//        cout << s1 << " " << s2 << endl;
//        cout << u1 << " " << u2 << endl;
        if(s1==u1)
                return 1;
        return 0;
}
 
int oddp[mxn];          // i theke baam e daan e kototuk expand kora jay
int evep[mxn];          // i,i+1 theke baam e daan e kototuk expand kora jay
int tot_palin = 0;      // tot_palin_seq
 
void calc_p()
{
 
        For(i,s.sz)
        {
                int lo = 0 , hi = min ( i , (int)s.sz - 1 - i) , ans , mid;
                while(lo<=hi)
                {
                        mid = (lo+hi)/2;
 
                        int l = i - mid;
                        int r = i + mid;
 
                        if(ispalin(l,r))
                        {
//                                cout << i << " " << l << " " << r << endl;
                                ans = mid;
                                lo = mid + 1;
                        }
                        else
                                hi = mid - 1;
                }
 
                oddp[i] = ans;
 
//                cout << i << " " << ans << endl;
        }
 
        For(i,(int)s.sz-1)
        {
                int lo = 0 , hi = min ( i , (int)s.sz - 1 - i - 1) , ans = -1, mid;
                while(lo<=hi)
                {
                        mid = (lo+hi)/2;
 
                        int l = i - mid;
                        int r = i + mid + 1;
 
                        if(ispalin(l,r))
                        {
//                                cout << i << " " << l << " " << r << endl;
                                ans = mid;
                                lo = mid + 1;
                        }
                        else
                                hi = mid - 1;
                }
 
                evep[i] = ans;
 
//                cout << i << " " << ans << endl;
        }
}
 
 
string longest_palin()
{
        int mx = 0 , l , r;
        For(i,s.sz)                     // odd calc
        {
                tot_palin += oddp[i] + 1;
                int ll = i - oddp[i];
                int rr = i + oddp[i];
 
                if(rr-ll+1>mx)
                {
                        mx = rr-ll + 1;
                        r = rr;
                        l = ll;
                }
 
        }
 
        For(i,(int)s.sz-1)                     // even calc
        {
                if(evep[i]!=-1)
                        tot_palin += evep[i] + 1;
                int ll = i - evep[i];
                int rr = i + 1 + evep[i];
 
                if(rr-ll+1>mx)
                {
                        mx = rr-ll + 1;
                        r = rr;
                        l = ll;
                }
        }
 
        string ans;
 
        Fre(i,l,r+1)
                ans += s[i];
 
        return ans;
}
 
int main()
{
 
 
        prime_calc();
        cin >> s;
        hash_calc();
        calc_p();
 
        string lps = longest_palin();
 
        cout << lps.sz << endl;
        cout << lps << endl;
 
 
 
 
 
 
 
 
 
 
 
 
 
        return 0;
}
 
