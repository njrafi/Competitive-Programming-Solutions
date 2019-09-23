#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n, m, x, d;
int main()
{
    scanf("%lld %lld", &n, &m);
    ll nn = n / 2;
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld", &x, &d);
        sum += n * x;
        if (d >= 0)
            sum += ((n - 1) * n) / 2 * d;
        else
        {
            if (n & 1)
                sum += nn * (nn + 1) * d;
            else
                sum += ((nn * (nn + 1)) / 2 + ((nn - 1) * nn) / 2) * d;
        }
    }
    printf("%.8f\n", 1.0 * sum / n);
    //    main();
}