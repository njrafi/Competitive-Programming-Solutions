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
 
 
 
i64 mod = 10e9;
 
i64 f(int n)
{
        if(n < 3) return 1;
        if(n % 2) return 3 * f( n - 2);
        else return 2 * f(n-1) - f(n-2) + 2;
}
 
i64 fSum(int l,int r)
{
        i64 sum = 0;
        Fre(i,l,r+1)
                sum += f(i);
        return sum % mod;
}
struct matrix
{
        i64 mat[5][5],row,col;
        matrix() {}
        matrix(int row,int col)
        {
                this->row = row;
                this->col = col;
                For(i,row)
                        For(j,col)
                                mat[i][j] = 0;
        }
 
};
 
matrix identity(matrix a)
{
        For(i,a.row)
                For(j,a.row)
                {
                        if(i==j)
                                a.mat[i][j] = 1;
                        else
                                a.mat[i][j] = 0;
                }
        return a;
}
 
void print(matrix a)
{
        For(i,a.row)
        {
                For(j,a.col)
                        cerr << a.mat[i][j]<< " ";
                cerr << endl;
        }
}
matrix multiply(matrix a , matrix b,i64 m = mod)
{
        matrix r;
        r.row = a.row;
        r.col = b.col;
 
        For(i,r.row)
                For(j,r.col)
                {
                        i64 sum = 0;
                        For(k,a.col)
                                sum = ( sum + ( a.mat[i][k] * b.mat[k][j] ) ) % m;
                        r.mat[i][j] = sum;
                }
        return r;
}
 
 
// finding a^p
matrix power(matrix a,i64 p,i64 m = mod)
{
        if(!p)
                return identity(a);
        if(p==1)
                return a;
        if(p%2==1)
                return multiply(a,power(a,p-1,m),m);
        matrix r = power(a,p/2,m);
        r = multiply(r,r,m);
        return r;
}
 
matrix setvalue()
{
        matrix r = matrix(4,4);
        r.mat[0][0] = 3 % mod;
        r.mat[1][0] = 6 % mod;
        r.mat[1][1] = (-1 + mod) % mod;
        r.mat[1][2] = r.mat[2][2] = 1 % mod;
        r.mat[3][0] = 9 % mod;
        r.mat[3][1] = ( -1 + mod) % mod;
        r.mat[3][2] = 1 % mod;
        r.mat[3][3] = 1 % mod;
        return r;
}
 
 
i64 get_val(int n)
{
        if(!n) return 0;
        if(n < 3) return 1;
        matrix bm = setvalue();
//        print(bm);
        bm = power(bm,(n+1)/2-1,mod);
//        print(bm);
        vi base = {1,1,2,2};
        i64 ans = 0;
        int row = 1 - n % 2;
        For(i,base.sz)
                ans += bm.mat[row][i] * base[i];
        return ans % mod;
}
 
 
i64 get_sum(i64 n)
{
        if(!n) return 0;
        if(n < 3) return n;
        matrix bm = setvalue();
//        print(bm);
        i64 k = (n+1)/2;
        bm = power(bm,k-1,mod);
//        print(bm);
        vi base = {1 % mod,1% mod,2% mod,2% mod};
        i64 odd = 0;
        i64 even = 0;
        i64 sum = 0;
        int row = 1 - n % 2;
 
        For(i,base.sz)
        {
                odd += bm.mat[0][i] * base[i];
                even += bm.mat[1][i] * base[i];
                sum += bm.mat[3][i] * base[i];
        }
 
        odd %= mod;
        even %= mod;
        sum %= mod;
 
//        cout << odd << " " << even << " " << sum << endl;
        if(row) even = 0;
 
        return ( (sum - even) % mod + mod) % mod;
}
 
int main()
{
 
//        Fre(i,1,20)
//                cout << i << " " << f(i) << endl;
        i64 t,n;
        cin >> t >> mod;
        while(t--)
        {
//                cin >> n;
//                cout << f(n) << " " << get_val(n) << endl;
                i64 l,r;
                cin >> l >> r;
                assert(l <= r);
                cout << ( ( get_sum(r) - get_sum(l-1) )%mod + mod) % mod << endl;
//                cout << fSum(l,r) << endl;
        }
 
        return 0;
}
 
 
 
 
 
 
 
