#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define i64 long long
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
#define ff first
#define ss second
#define clr(a) memset(a, -1, sizeof(a))
int main()
{
    int res = 0, n, inp, l_inp, home = 0;
    cin >> n;
    while (n--)
    {
        cin >> inp;
        if (inp)
        {
            res++;
            break;
        }
    }
    l_inp = inp;
    if (n == -1)
    {
        cout << res << endl;
        return 0;
    }
    while (n--)
    {
        cin >> inp;
        if (l_inp && inp)
            res++;
        else if (!l_inp && inp)
            if (home)
            {
                res++;
                home = 0;
            }
            else
                res += 2;
        else if (!inp)
            if (!l_inp)
                home = 1;
        l_inp = inp;
    }
    cout << res << endl;
    return 0;
}
