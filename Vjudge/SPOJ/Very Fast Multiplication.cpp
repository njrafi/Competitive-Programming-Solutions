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



const double PI = 3.141592653589793238460;

typedef complex<double> Complex;
typedef valarray<Complex> CArray;

// Cooley–Tukey FFT (in-place)
void fft(CArray& x)
{
        const size_t N = x.size();
        if (N <= 1) return;

        // divide
        CArray even = x[slice(0, N/2, 2)];
        CArray  odd = x[slice(1, N/2, 2)];

        // conquer
        fft(even);
        fft(odd);

        // combine
        for (size_t k = 0; k < N/2; ++k)
        {
                Complex t = polar(1.0, -2 * PI * k / N) * odd[k];
                x[k    ] = even[k] + t;
                x[k+N/2] = even[k] - t;
        }
}

// inverse fft (in-place)
void ifft(CArray& x)
{
        // conjugate the complex numbers
        x = x.apply(conj);

        // forward fft
        fft( x );

        // conjugate the complex numbers again
        x = x.apply(conj);

        // scale the numbers
        x /= x.size();
}


// make them same size before sending
// get multiplication of 2 polynomial v1 and v2


/// let (1 + 2x + 3x^2) * (3 + 2x + x^2) = (3 + 8x + 14x^2 + 8x^3 + 3x^4)
/// we input (1,2,3) and (3,2,1) and get (3,8,14,6,3)

vector<i64> get_mul(vi v1,vi v2)
{
        int N = v1.sz;
        int padded_size = 2 * (1 << int(ceil(log2(N))));
        vector<Complex> num1_vec(padded_size - N, 0.0), num2_vec(padded_size - N, 0.0);

        For(i,N)
                num1_vec.pb(v1[i]);

        For(i,N)
                num2_vec.pb(v2[i]);

        CArray data1(padded_size);

        For(i,padded_size)
                data1[i] = num1_vec[i];

        CArray data2(padded_size);

        For(i,padded_size)
                data2[i] = num2_vec[i];

        fft(data1);
        fft(data2);

        CArray data3(padded_size);
        data3 = data1 * data2;

        ifft(data3);

        vector<i64> ans;
        For(i,padded_size-1)
                ans.pb((long long)(round(data3[i].real())));

        vector<i64> ret;
        for(int i = padded_size - 1 - (2*N - 1); i < padded_size - 1; i++)
                ret.pb(ans[i]);

        return ret;

}

// get multiplication of 2 big numbers
string big_num_mul(string s1,string s2)
{
        reverse(all(s1));
        reverse(all(s2));

        while(s1.sz<s2.sz)
                s1 += '0';
        while(s2.sz<s1.sz)
                s2 += '0';

        vi v1,v2;

        For(i,s1.sz)
                v1.pb(s1[i]-'0');

        For(i,s2.sz)
                v2.pb(s2[i]-'0');

        vector<i64> v = get_mul(v1,v2);

        string res;
        i64 carry = 0;
        For(i,v.sz)
        {


                i64 now = v[i] % 10;
                now += carry % 10;
                carry /= 10;
                if(now>=10)
                {

                        carry += now/10;
                        now %= 10;

                }
                carry += v[i] / 10;
                res += (now + '0');

        }


        while(carry)
        {
                res += (carry % 10) + '0';
                carry /= 10;
        }
        while(res.back()=='0')
                res.pop_back();

        reverse(all(res));
        if(res.empty())
                res += '0';

        return res;
}

int main()
{


        int t;
        string s1,s2;
        sf(t);
        while(t--)
        {
                cin >> s1 >> s2;

                cout << big_num_mul(s1,s2) << endl;
        }












        return 0;
}