#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
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
#define For(i, n) for (int i = 0; i < n; i++)
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
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(i64 *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
int main()
{
    freopen("buffcraft.in", "r", stdin);
    freopen("buffcraft.out", "w", stdout);
    int b, k, cd, cp, inp;
    cin >> b >> k >> cd >> cp;
    if (k > cp + cd)
        k = cp + cd;
    vpi d, p;
    for (int i = 1; i <= cd; i++)
    {
        cin >> inp;
        d.pb(mp(inp, i));
    }
    for (int i = 1; i <= cp; i++)
    {
        cin >> inp;
        p.pb(mp(inp, i));
    }
    sort(all(d));
    sort(all(p));
    reverse(all(d));
    reverse(all(p));
    vector<i64> dc, pc;
    dc.pb(0);
    pc.pb(0);
    For(i, d.sz)
        dc.pb(d[i].ff + dc[i]);
    For(i, p.sz)
        pc.pb(p[i].ff + pc[i]);
    /* For(i,dc.sz)
        cout << dc[i] << " "; */
    int ans;
    long double mx = -1, sum;
    For(i, k + 1)
    {
        if (dc.sz > i && pc.sz > k - i)
        {
            sum = ((b + dc[i]) * (100 + pc[k - i])) / 100.0;
            //cout << sum << endl;
            if (sum > mx)
            {
                mx = sum;
                ans = i;
            }
        }
    }
    cout << ans << " " << k - ans << endl;
    For(i, ans)
            cout
        << d[i].ss << " ";
    cout << endl;
    For(i, k - ans)
            cout
        << p[i].ss << " ";
    cout << endl;
    return 0;
}