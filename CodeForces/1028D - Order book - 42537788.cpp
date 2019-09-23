#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define sf(n) scanf("%d", &n)
#define For(i, n) for (int i = 0; i < n; i++)
#define i64 long long int
#define pb push_back
#define sz size()
#define mod 1000000007
#define inf INT_MAX / 2
priority_queue<int> l;
priority_queue<int, vi, greater<int>> r;
vi pen;
i64 ans;
void add(int val)
{
    if (val < l.top())
        l.push(val);
    else if (val > r.top())
        r.push(val);
    else
        pen.pb(val);
}
void process(int val)
{
    bool ok = 0;
    For(i, pen.sz) if (pen[i] < val)
    {
        if (pen[i] > r.top())
        {
            puts("0");
            exit(0);
        }
        l.push(pen[i]);
    }
    else if (pen[i] > val)
    {
        if (pen[i] < l.top())
        {
            puts("0");
            exit(0);
        }
        r.push(pen[i]);
    }
    else
    {
        if (pen[i] > l.top() && pen[i] < r.top())
        {
            ok = 1;
            ans *= 2;
            ans %= mod;
        }
        else
        {
            puts("0");
            exit(0);
        }
    }
    pen.clear();
    if (l.top() == val)
    {
        l.pop();
        ok = 1;
    }
    if (r.top() == val)
    {
        r.pop();
        ok = 1;
    }
    if (!ok)
    {
        puts("0");
        exit(0);
    }
}
int main()
{
    l.push(-inf);
    r.push(inf);
    ans = 1;
    int n, inp;
    sf(n);
    char s[10];
    while (n--)
    {
        scanf("%s", s);
        sf(inp);
        if (s[1] == 'D')
            add(inp);
        else
            process(inp);
    }
    i64 tot = 0;
    For(i, pen.sz) if (l.top() < pen[i] && pen[i] < r.top())
        tot++;
    //        cout << ans << endl;
    ans *= (tot + 1);
    ans %= mod;
    cout << ans << endl;
    return 0;
}