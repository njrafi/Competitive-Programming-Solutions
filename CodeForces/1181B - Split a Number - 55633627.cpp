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
#define pii pair<int, int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int, vector<int>, greater<int>>
#define mpi map<int, int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX / 2
#define infll LLONG_MAX / 3
#define For(i, n) for (int i = 0; i < n; i++)
#define Fre(i, a, b) for (int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
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
struct Bigint
{
    string a;
    int sign;
    Bigint() {}
    Bigint(string b) { (*this) = b; }
    int size() { return a.size(); }
    Bigint inverseSign()
    {
        sign *= -1;
        return (*this);
    }
    Bigint normalize(int newSign)
    {
        sign = newSign;
        for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--)
            a.erase(a.begin() + i);
        if (a.size() == 1 && a[0] == '0')
            sign = 1;
        return (*this);
    }
    void operator=(string b)
    {
        a = b[0] == '-' ? b.substr(1) : b;
        reverse(a.begin(), a.end());
        this->normalize(b[0] == '-' ? -1 : 1);
    }
    bool operator<(const Bigint &b) const
    {
        if (a.size() != b.a.size())
            return a.size() < b.a.size();
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != b.a[i])
                return a[i] < b.a[i];
        return false;
    }
    Bigint operator+(Bigint b)
    {
        if (sign != b.sign)
            return (*this) - b.inverseSign();
        Bigint c;
        for (int i = 0, carry = 0; i < (int)a.size() || i < (int)b.size() || carry; i++)
        {
            carry += (i < (int)a.size() ? a[i] - 48 : 0) + (i < (int)b.a.size() ? b.a[i] - 48 : 0);
            c.a += (carry % 10 + 48);
            carry /= 10;
        }
        return c.normalize(sign);
    }
    Bigint operator-(Bigint b)
    {
        if (sign != b.sign)
            return (*this) + b.inverseSign();
        if ((*this) < b)
            return (b - (*this)).inverseSign();
        Bigint c;
        for (int i = 0, borrow = 0; i < (int)a.size(); i++)
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(sign);
    }
    Bigint operator*(Bigint b)
    {
        Bigint c("0");
        for (int i = 0, k = a[i]; i < (int)a.size(); i++, k = a[i])
        {
            while (k-- - 48)
                c = c + b;
            b.a.insert(b.a.begin(), '0');
        }
        return c.normalize(sign * b.sign);
    }
    Bigint operator/(Bigint b)
    {
        if (b.size() == 1 && b.a[0] == '0')
            b.a[0] /= (b.a[0] - 48);
        Bigint c("0"), d;
        for (int j = 0; j < (int)a.size(); j++)
            d.a += "0";
        int dSign = sign * b.sign;
        b.sign = 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b))
                c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }
    Bigint operator%(Bigint b)
    {
        if (b.size() == 1 && b.a[0] == '0')
            b.a[0] /= (b.a[0] - 48);
        Bigint c("0");
        int cSign = sign * b.sign;
        b.sign = 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            c.a.insert(c.a.begin(), '0');
            c = c + a.substr(i, 1);
            while (!(c < b))
                c = c - b;
        }
        return c.normalize(cSign);
    }
    void print()
    {
        if (sign == -1)
            putchar('-');
        for (int i = a.size() - 1; i >= 0; i--)
            putchar(a[i]);
    }
    string get()
    {
        string gg;
        if (sign == -1)
            gg += '-';
        for (int i = a.size() - 1; i >= 0; i--)
            gg += a[i];
        return gg;
    }
};
bool f(string a, string b)
{
    if (a.sz == b.sz)
        return a < b;
    return a.sz < b.sz;
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string w;
    int rem = s.sz;
    vpi v;
    For(i, (int)s.sz - 1)
    {
        w += s[i];
        rem--;
        if (s[i + 1] != '0')
            v.pb({max((int)w.sz, rem), i + 1});
    }
    sort(all(v));
    int highestSize = v[0].ff;
    //        cerr << highestSize << endl;
    vs ans;
    For(i, v.sz)
    {
        if (v[i].ff != highestSize)
            break;
        int st = v[i].ss;
        string s1, s2;
        For(j, st)
            s1 += s[j];
        Fre(j, st, s.sz)
            s2 += s[j];
        Bigint a, b, c;
        a = s1;
        b = s2;
        c = a + b;
        ans.pb(c.get());
    }
    sort(all(ans), f);
    cout << ans[0] << endl;
    return 0;
}
