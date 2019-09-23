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
#define vll vector<i64>
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
#define For(i, n) for (int i = 0; i < n; i++)
#define Fre(i, a, b) for (int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "r", stdin)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//i64 dp[60][60];
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
string s;
set<string> ans;
void func2(int index);
void func3(int index);
int dp[10][10005];
void func2(int index)
{
    string tem, tem2;
    if (index - 1 < 0)
        return;
    if (dp[2][index])
        return;
    dp[2][index] = 1;
    for (int i = index - 1; i <= index; i++)
        tem.pb(s[i]);
    ans.insert(tem);
    bool flag = 0;
    if (index - 3 >= 0)
    {
        for (int i = index - 3; i <= index - 2; i++)
            tem2.pb(s[i]);
        if (tem2 == tem)
        {
            func3(index - 2);
            flag = 1;
        }
    }
    if (!flag)
    {
        func2(index - 2);
        func3(index - 2);
    }
}
void func3(int index)
{
    string tem, tem2;
    if (index - 2 < 0)
        return;
    if (dp[3][index])
        return;
    dp[3][index] = 1;
    for (int i = index - 2; i <= index; i++)
        tem.pb(s[i]);
    ans.insert(tem);
    bool flag = 0;
    if (index - 5 >= 0)
    {
        for (int i = index - 5; i <= index - 3; i++)
            tem2.pb(s[i]);
        if (tem2 == tem)
        {
            func2(index - 3);
            flag = 1;
        }
    }
    if (!flag)
    {
        func2(index - 3);
        func3(index - 3);
    }
}
int main()
{
    cin >> s;
    string tem;
    mem(dp, 0);
    if (s.sz <= 6)
    {
        cout << 0;
        return 0;
    }
    Fre(i, 5, s.sz)
        tem.pb(s[i]);
    s = tem;
    func2(s.sz - 1);
    func3(s.sz - 1);
    cout << ans.sz << endl;
    set<string>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
        cout << *it << endl;
    return 0;
}
