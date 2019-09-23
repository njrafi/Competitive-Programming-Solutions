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
#define endl '\n'
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//functions
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
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
bool cmp(pii a, pii b)
{
    return abs(a.ff) + abs(a.ss) < abs(b.ff) + abs(b.ss);
}
int main()
{
    int t, x, y, cnt = 0;
    cin >> t;
    vpi v;
    while (t--)
    {
        cin >> x;
        cin >> y;
        v.pb(mp(x, y));
        if (x == 0 || y == 0)
            cnt += 4;
        else
            cnt += 6;
    }
    sort(all(v), cmp);
    // For(i,v.sz)
    //      cout << v[i].ff << " " << v[i].ss << endl;
    cout << cnt << endl;
    For(i, v.sz)
    {
        x = v[i].ff;
        y = v[i].ss;
        if (x && y)
        {
            cout << 1 << " " << abs(x) << " ";
            if (x > 0)
                cout << "R";
            else
                cout << "L";
            cout << endl;
            cout << 1 << " " << abs(y) << " ";
            if (y > 0)
                cout << "U";
            else
                cout << "D";
            cout << endl;
        }
        if (x == 0)
        {
            cout << 1 << " " << abs(y) << " ";
            if (y > 0)
                cout << "U";
            else
                cout << "D";
            cout << endl;
        }
        else if (y == 0)
        {
            cout << 1 << " " << abs(x) << " ";
            if (x > 0)
                cout << "R";
            else
                cout << "L";
            cout << endl;
        }
        cout << 2 << endl;
        if (x && y)
        {
            cout << 1 << " " << abs(x) << " ";
            if (x > 0)
                cout << "L";
            else
                cout << "R";
            cout << endl;
            cout << 1 << " " << abs(y) << " ";
            if (y > 0)
                cout << "D";
            else
                cout << "U";
            cout << endl;
        }
        if (x == 0)
        {
            cout << 1 << " " << abs(y) << " ";
            if (y > 0)
                cout << "D";
            else
                cout << "U";
            cout << endl;
        }
        else if (y == 0)
        {
            cout << 1 << " " << abs(x) << " ";
            if (x > 0)
                cout << "L";
            else
                cout << "R";
            cout << endl;
        }
        cout << 3 << endl;
    }
    return 0;
}
