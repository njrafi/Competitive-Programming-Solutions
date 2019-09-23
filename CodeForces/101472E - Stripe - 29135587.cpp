///HEADERS
#include <bits/stdc++.h>
///PREPROCESSORS
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1, rgt = (node << 1) + 1, md = (st + ed) >> 1;
#define pii pair<int, int>
#define mpr make_pair
#define EPS 1e-9
#define sqr(x) ((x) * (x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0 / (2 * x) - 1.0 / (12 * sqr(x))
#define joshephus(n, k)                  \
    j(int n, int k)                      \
    {                                    \
        ll res = 1;                      \
        for (ll i = 2; i <= n; i++)      \
            res = (res + k - 1) % i + 1; \
        return res;                      \
    }
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);
using namespace std;
struct info
{
    int x, y, z;
    info() { x = y = z = 0; }
    info(int xx, int yy = 0, int zz = 0)
    {
        x = xx;
        y = yy;
        z = zz;
    }
};
//info mn(info a, info b) {
//    return info( (a.x == b.x && a.y > b.y) || a.x < b.x;
//}
bool cmpx(info x, info y)
{
    return x.x < y.x;
}
bool cmpy(info x, info y)
{
    return x.y < y.y;
}
int n, h, b, e, price[LIM + 100];
string cmd[24];
int targ, pr, lev;
info ans[3020000];
int f(int in, int col, int row, int sz, int cn)
{
    //    cout << "STATE " << in << ' ' << col << ' ' << row << ' ' << sz << ' ' << cn << endl; getchar();
    if (in == lev)
        return row;
    if (cmd[in] == "LU")
    {
        if (col < sz / 2)
            return f(in + 1, sz / 2 - col - 1, cn - row - 1, sz / 2, cn * 2);
        else
            return f(in + 1, col % (sz / 2), row + cn, sz / 2, cn * 2);
    }
    if (cmd[in] == "LD")
    {
        if (col < sz / 2)
            return f(in + 1, sz / 2 - col - 1, (cn - row - 1) + cn, sz / 2, cn * 2);
        else
            return f(in + 1, col % (sz / 2), row, sz / 2, cn * 2);
    }
    if (cmd[in] == "RU")
    {
        if (col < sz / 2)
            return f(in + 1, col % (sz / 2), row + cn, sz / 2, cn * 2);
        else
            return f(in + 1, sz / 2 - col % (sz / 2) - 1, (cn - row - 1), sz / 2, cn * 2);
    }
    if (cmd[in] == "RD")
    {
        if (col < sz / 2)
            return f(in + 1, col % (sz / 2), row, sz / 2, cn * 2);
        else
            return f(in + 1, sz / 2 - col % (sz / 2) - 1, (cn - row - 1) + cn, sz / 2, cn * 2);
    }
}
int main()
{
    freopen("E.IN", "r", stdin);
    //    freopen("o.txt", "w",stdout);
    int T;
    //    scanf("%d", &T);
    while ((cin >> cmd[0]))
    {
        targ = 1LL << 21;
        pr = 1024;
        lev = 21;
        //         targ = 8;
        //         pr = 5;
        //         lev = 3;
        for (int i = 1; i < lev; i++)
            cin >> cmd[i];
        for (int i = 0; i < targ; i++)
        {
            ans[i].x = i;
            ans[i].y = f(0, i, 0, targ, 1); ///f(0, col, row, sz, cn);
                                            //            cout << i << ' ' << ans[i].y << endl; getchar();
        }
        //        for(int i=0; i<targ; i++) cout << ans[i].x << ' ' << ans[i].y << endl;
        sort(ans, ans + targ, cmpy);
        //        cout << "SORTED " << endl;
        //        for(int i=0; i<targ; i++) cout << ans[i].x << ' ' << ans[i].y << endl;
        for (int i = 0; i < pr; i++)
        {
            //            if(i > 0) printf(" ");
            printf("%d\n", ans[i].x + 1);
        }
        //        printf("\n");
    }
    return 0;
}