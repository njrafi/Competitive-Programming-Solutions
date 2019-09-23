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
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
int main()
{
    int n, cmpb, cmp, inp, i, cmpi, start = 0;
    vi v;
    cin >> n;
    while (n--)
    {
        sf(inp);
        v.pb(inp);
    }
    int mx = INT_MIN;
    while (1)
    {
        cmp = v[start];
        cmpi = start;
        int mode = 0;
        n = v.sz;
        for (i = start; i < v.sz; i++)
        {
            if (mode == 0)
            {
                if (v[i] == cmp)
                    cmpi = i;
                else if (v[i] == cmp + 1)
                {
                    mode = 1;
                    cmpb = i;
                }
                else if (v[i] == cmp - 1)
                {
                    mode = -1;
                    cmpb = i;
                }
            }
            else if (mode == 1)
            {
                if (v[i] == cmp)
                    cmpi = i;
                else if (v[i] == cmp + 1)
                    cmpb = i;
                else if (v[i] == cmp + 2)
                {
                    mx = max(mx, i - start);
                    start = cmpi + 1;
                    break;
                }
                else if (v[i] == cmp - 1)
                {
                    mx = max(mx, i - start);
                    start = cmpb + 1;
                    break;
                }
            }
            else if (mode == -1)
            {
                if (v[i] == cmp)
                    cmpi = i;
                else if (v[i] == cmp - 1)
                    cmpb = i;
                else if (v[i] == cmp + 1)
                {
                    mx = max(mx, i - start);
                    start = cmpb + 1;
                    break;
                }
                else if (v[i] == cmp - 2)
                {
                    mx = max(mx, i - start);
                    start = cmpi + 1;
                    break;
                }
            }
        }
        if (i == n)
        {
            mx = max(mx, n - start);
            break;
        }
    }
    cout << mx;
    return 0;
}
