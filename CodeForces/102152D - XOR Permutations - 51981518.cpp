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
i64 po(i64 a, i64 b)
{
    i64 ans = 1;
    while (b--)
        ans *= a;
    return ans;
}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int two[12];
void pre()
{
    For(i, 12)
        two[i] = po(2, i);
}
int dp[11][11][11][11];
int f(int pos, int o1, int o2, int o3)
{
    if (pos == 0)
        return 0;
    int z1 = pos - o1;
    int z2 = pos - o2;
    int z3 = pos - o3;
    int ans = 0;
    if (dp[pos][o1][o2][o3] != -1)
        return dp[pos][o1][o2][o3];
    For(i, 2)
    {
        if (!i && !z1)
            continue;
        if (i && !o1)
            continue;
        For(j, 2)
        {
            if (!j && !z2)
                continue;
            if (j && !o2)
                continue;
            For(k, 2)
            {
                if (!k && !z3)
                    continue;
                if (k && !o3)
                    continue;
                int temo1 = o1 - (i == 1);
                int temo2 = o2 - (j == 1);
                int temo3 = o3 - (k == 1);
                int cost = two[pos - 1] * (i ^ k ^ j);
                ans = max(ans, cost + f(pos - 1, temo1, temo2, temo3));
            }
        }
    }
    return dp[pos][o1][o2][o3] = ans;
}
void conv(int num)
{
    string s;
    while (num)
    {
        s += (num % 2) + '0';
        //                cout << num % 2 << " ";
        num /= 2;
    }
    while (s.sz != 10)
        s += '0';
    reverse(all(s));
    cout << s << endl;
}
int main()
{
    pre();
    string s;
    int t;
    cin >> t;
    while (t--)
    {
        int o1 = 0, o2 = 0, o3 = 0;
        cin >> s;
        For(i, s.sz) if (s[i] == '1')
            o1++;
        cin >> s;
        For(i, s.sz) if (s[i] == '1')
            o2++;
        cin >> s;
        For(i, s.sz) if (s[i] == '1')
            o3++;
        //                cout << f(10,o1,o2,o3) << endl;
        mem(dp, -1);
        conv(f(10, o1, o2, o3));
    }
    return 0;
}
