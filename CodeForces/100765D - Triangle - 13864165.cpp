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
#define eps 1e-8
#define ff first
#define ss second
#define clr(a) memset(a, -1, sizeof(a))
#define rset(a) memset(a, 0, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "r", stdin)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
vs s;
string s3;
void func(int x, int y)
{
    string s1, s2;
    s3.clear();
    s1 = s[x];
    s2 = s[y];
    int mx = 0, rem, tem;
    reverse(all(s1));
    reverse(all(s2));
    mx = max(s1.sz, s2.sz);
    tem = mx - s1.sz;
    while (tem--)
        s1.pb('0');
    tem = mx - s2.sz;
    while (tem--)
        s2.pb('0');
    rem = 0;
    for (int j = 0; j < mx; j++)
    {
        tem = s1[j] - '0' + s2[j] - '0' + rem;
        s3.pb(tem % 10 + '0');
        rem = tem / 10;
    }
    if (rem)
        s3.pb(rem + '0');
    reverse(all(s3));
}
bool cmp(string s1, string s2)
{
    if (s1.sz != s2.sz)
        return (s1.sz < s2.sz);
    else
        return s1 < s2;
}
int f(int x, int y, int z)
{
    func(x, y);
    if (s3.sz > s[z].sz)
        return 1;
    else if (s3.sz == s[z].sz)
        if (s[z] < s3)
            return 1;
        else
            return 0;
    else
        return 0;
}
int main()
{
    int n;
    string inp;
    cin >> n;
    while (n--)
    {
        cin >> inp;
        s.pb(inp);
    }
    sort(all(s), cmp);
    for (int i = 0; i < s.sz - 2; i++)
    {
        if (f(i, i + 1, i + 2))
        {
            cout << s[i] << " " << s[i + 1] << " " << s[i + 2] << endl;
            return 0;
        }
    }
    printf("0 0 0\n");
    return 0;
}