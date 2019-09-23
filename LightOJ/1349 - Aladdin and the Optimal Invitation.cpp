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
inline void fastRead(int *a)
{
    register char c = 0;
    while (c < 33)
        c = gc();
    *a = 0;
    while (c > 33)
    {
        *a = *a * 10 + c - '0';
        c = gc();
    }
}
inline void fastWrite(int a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc('\n');
}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
#define mxn 50005
int x[mxn];
int y[mxn];
int main()
{
    int t, cs = 1, n, m, q, a, b, c;
    fastRead(&t);
    while (t--)
    {
        mem(x, 0);
        mem(y, 0);
        fastRead(&n);
        fastRead(&m);
        fastRead(&q);
        i64 tot = 0;
        i64 totsumX = 0;
        i64 totsumY = 0;
        while (q--)
        {
            fastRead(&a);
            fastRead(&b);
            fastRead(&c);
            x[a] += c;
            y[b] += c;
            tot += c;
            totsumX += c * a;
            totsumY += c * b;
        }
        i64 rem = tot;
        i64 now = 0;
        i64 sum = 0;
        i64 mnDiff = infll;
        int row;
        Fre(i, 1, n + 1)
        {
            rem -= x[i];
            now += x[i];
            sum += x[i] * i;
            i64 l = now * i - sum;
            i64 r = (totsumX - sum) - rem * i;
            if (l + r < mnDiff)
            {
                mnDiff = l + r;
                row = i;
            }
            else
                break;
            //                        cout << i << " " << l << " " << r << endl;
        }
        rem = tot;
        now = 0;
        sum = 0;
        mnDiff = infll;
        int col;
        Fre(i, 1, m + 1)
        {
            rem -= y[i];
            now += y[i];
            sum += y[i] * i;
            i64 l = now * i - sum;
            i64 r = (totsumY - sum) - rem * i;
            if (l + r < mnDiff)
            {
                mnDiff = l + r;
                col = i;
            }
            else
                break;
            //                        cout << i << " " << l << " " << r << endl;
        }
        CASE(cs++);
        pfs(row);
        fastWrite(col);
    }
    return 0;
}
