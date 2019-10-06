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
 
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
 
 
#define mxn 200005
 
 
 
 
/// Fast Walsh-Hadamard Transformation in n log n
namespace fwht  /// hash = 840614
{
const int OR = 0;
const int AND = 1;
const int XOR = 2;
 
long long P1[mxn], P2[mxn];
 
void walsh_transform(long long* ar, int n, int flag = XOR)
{
 if (n == 0)
  return;
 
 int i, m = n / 2;
 walsh_transform(ar, m, flag);
 walsh_transform(ar + m, m, flag);
 
 for (i = 0; i < m; i++)  /// Don't forget modulo if required
 {
  long long x = ar[i], y = ar[i + m];
  if (flag == OR)
   ar[i] = x, ar[i + m] = x + y;
  if (flag == AND)
   ar[i] = x + y, ar[i + m] = y;
  if (flag == XOR)
   ar[i] = x + y, ar[i + m] = x - y;
 }
}
 
void inverse_walsh_transform(long long* ar, int n, int flag = XOR)
{
 if (n == 0)
  return;
 
 int i, m = n / 2;
 inverse_walsh_transform(ar, m, flag);
 inverse_walsh_transform(ar + m, m, flag);
 
 for (i = 0; i < m; i++)  /// Don't forget modulo if required
 {
  long long x = ar[i], y = ar[i + m];
  if (flag == OR)
   ar[i] = x, ar[i + m] = y - x;
  if (flag == AND)
   ar[i] = x - y, ar[i + m] = y;
  if (flag == XOR)
   ar[i] = (x + y) >> 1, ar[i + m] = (x - y) >> 1; /// Modular inverse if required here
 }
}
 
vector <long long> convolution(int n, long long* A, long long* B, int flag = XOR)
{
 assert(__builtin_popcount(n) == 1); /// n must be a power of 2
 for (int i = 0; i < n; i++)
  P1[i] = A[i];
 for (int i = 0; i < n; i++)
  P2[i] = B[i];
 
 walsh_transform(P1, n, flag);
 walsh_transform(P2, n, flag);
 for (int i = 0; i < n; i++)
  P1[i] = P1[i] * P2[i];
 inverse_walsh_transform(P1, n, flag);
 return vector<long long> (P1, P1 + n);
}
 
/// For i = 0 to n - 1, j = 0 to n - 1
/// v[i or j] += A[i] * B[j]
vector <long long> or_convolution(int n, long long* A, long long* B)
{
 return convolution(n, A, B, OR);
}
 
/// For i = 0 to n - 1, j = 0 to n - 1
/// v[i and j] += A[i] * B[j]
vector <long long> and_convolution(int n, long long* A, long long* B)
{
 return convolution(n, A, B, AND);
}
 
/// For i = 0 to n - 1, j = 0 to n - 1
/// v[i xor j] += A[i] * B[j]
vector <long long> xor_convolution(int n, long long* A, long long* B)
{
 return convolution(n, A, B, XOR);
}
}
 
 
 
vpi v[mxn];
int dis[mxn];
 
 
void dfs(int node,int val)
{
 dis[node] = val;
// pfs(node);
// pfn(val);
 
 For(i,v[node].sz)
 {
  int vv = v[node][i].ff;
  int ww = v[node][i].ss;
 
  if(dis[vv]!=-1)
   continue;
 
  dfs(vv,val ^ ww);
 }
}
 
 
 
i64 a[1 << 18];
 
 
#define gg 17
 
i64 f(int n)
{
 int valSize = 1 << gg;
 mem(a,0);
 
        Fre(i,1,n+1)
                a[dis[i]]++;
 
        vector<i64> w = fwht::xor_convolution(valSize,a,a);
 
//        w[0] -= n;
        i64 ans = 0;
        For(i,w.sz)
        {
                if(!w[i]) continue;
//                cout << "first loop " << i << endl;
                ans += (w[i] * w[i]);
                ans %= mod;
                For(bit,gg)
                {
//                 cout << "second loop before toggle " << " " << bit << endl;
                        int newi = togglebit(i,bit);
//                        cout << "second loop " << i << " " << newi << endl;
                        if(newi < w.sz)
                        {
//                                cout << i << " " << newi << endl;
//                                cout << w[i] << " " << w[newi] << endl;
                                ans += w[i] * w[newi];
                                ans %= mod;
                        }
                }
        }
 
        return ans;
//        For(i,10)
//                printf("%d  %lld\n",i , w[i]);
}
 
 
 
int main()
{
// WRITE;
 int t,n,a,b,c,cs = 1;
 
        sf(n);
        mem(v,NULL);
 
        For(i,n-1)
        {
                sfff(a,b,c);
                v[a].pb(mp(b,c));
                v[b].pb(mp(a,c));
        }
 
        mem(dis,-1);
 
        dfs(1,0);
 
        cout << f(n) << endl;
 
 
 
 
 return 0;
}
