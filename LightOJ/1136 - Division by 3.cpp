#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, a, b, res1, res2;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        a--;
        res1 = (b + 2) / 3;
        res1 = b - res1;
        res2 = (a + 2) / 3;
        res2 = a - res2;
        printf("Case %d: %lld\n", i, res1 - res2);
    }
    return 0;
}
