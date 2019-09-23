#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long int s, n, x, y, mid;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> s;
        n = ceil(sqrt(s));
        mid = (n * n + (n - 1) * (n - 1) + 1) / 2;
        if (n % 2)
        {
            if (s == mid)
            {
                x = n;
                y = n;
            }
            else if (s > mid)
            {
                x = n - abs(s - mid);
                y = n;
            }
            else
            {
                x = n;
                y = n - abs(s - mid);
            }
        }
        else
        {
            if (s == mid)
            {
                x = n;
                y = n;
            }
            else if (s < mid)
            {
                x = n - abs(s - mid);
                y = n;
            }
            else
            {
                x = n;
                y = n - abs(s - mid);
            }
        }
        printf("Case %d: %lld %lld\n", i, x, y);
    }
    return 0;
}
