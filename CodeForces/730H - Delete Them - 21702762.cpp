#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
using namespace std;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 using namespace __gnu_pbds;
*/
/*
        two functions for policy based data structure. it is
                 find_by_order() and order_of_key().
         The first returns an iterator to the k-th largest element (counting from zero),
        the second returns the number of items in a set that are strictly smaller than our item
 */
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
#define Rep(i, x, y) for (int i = x; i <= y; i++)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "r", stdin)
#define sz size()
#define dbg(x) printf("yo is %d!\n", x)
#define dbg2(x, y) printf("yo is %d! and %d!\n", x, y)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//int dx[] = { -1, -1,  0, 1, 1, 1,  0, -1 };
//int dy[] = {  0, -1, -1, -1,  0, 1, 1, 1 };
//int dxK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
//int dyK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(i64 *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 power(i64 value, i64 base){i64 result = 1;For(i,base)result *= value;return result;}
//int Set(int N,int pos){return N = (1<<pos);}
//int reset(int N,int pos){return N &= (~(1<<pos));}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
//typedef tree< int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > Set;
int main()
{
    int n, m;
    cin >> n >> m;
    vs v;
    For(i, n)
    {
        string a;
        cin >> a;
        v.pb(a);
    }
    int len, flag = 1;
    vi V;
    For(i, m)
    {
        int a;
        cin >> a;
        a--;
        if (i == 0)
            len = v[a].sz;
        else
        {
            if (v[a].sz != len)
                flag = 0;
        }
        V.pb(a);
    }
    if (!flag)
    {
        cout << "No" << endl;
        return 0;
    }
    string ans;
    For(i, len)
    {
        int f = 1;
        char c = v[V[0]][i];
        Rep(j, 1, V.sz - 1)
        {
            if (c != v[V[j]][i])
            {
                f = 0;
                ans += '?';
                break;
            }
        }
        if (f)
            ans += c;
    }
    int st = 0;
    For(i, v.sz)
    {
        if (i == V[st])
        {
            st++;
            continue;
        }
        if (v[i].sz != ans.sz)
            continue;
        int fl = 1;
        For(j, ans.sz)
        {
            if (ans[j] == '?')
                continue;
            if (ans[j] != v[i][j])
            {
                fl = 0;
                break;
            }
        }
        if (fl)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl
         << ans << endl;
    return 0;
}