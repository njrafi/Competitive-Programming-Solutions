#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, inp, res;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        res = 0;
        cin >> n;
        while (n--)
        {
            cin >> inp;
            if (inp > 0)
                res += inp;
        }
        printf("Case %d: %d\n", i, res);
    }
    return 0;
}
