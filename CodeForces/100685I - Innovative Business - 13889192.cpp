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
int main()
{
    i64 W, L, w, l, ans = 0, tem1 = 0, tem2 = 0, rem1, vanga, rem2, lp, wp;
    cin >> W >> L >> w >> l;
    ans += (L / l) * (W / w);
    //cout << ans << endl;
    if (W % w)
    {
        rem1 = W % w;
        vanga = w / rem1;
        lp = L / l;
        ans += lp / vanga;
        if (lp % vanga)
        {
            ans++;
            tem1 = 1;
        }
    }
    if (L % l)
    {
        rem2 = L % l;
        vanga = l / rem2;
        wp = W / w;
        ans += wp / vanga;
        if (wp % vanga)
        {
            ans++;
            tem2 = 1;
        }
    }
    if (W % w || L % l)
        if (!tem1 && !tem2)
            ans++;
    cout << ans << endl;
    return 0;
}