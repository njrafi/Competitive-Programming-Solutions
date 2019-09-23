#include <bits/stdc++.h>
#define i64 long long int
#define mod 1000000007
#define LIM 100005
using namespace std;
i64 bigmod(i64 num, i64 n)
{
    num %= mod;
    if (n == 0)
        return 1;
    i64 x = bigmod(num, n / 2);
    x = x * x % mod;
    if (n % 2 == 1)
        x = x * num % mod;
    return x;
}
i64 modinverse(i64 num)
{
    return bigmod(num, mod - 2) % mod;
}
int n;
int a[LIM];
i64 mi[LIM];
int main()
{
    for (i64 i = 1; i <= 100000; i++)
        mi[i] = modinverse(i);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        i64 mul = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            mul *= a[i];
            if (mul > mod)
                mul %= mod;
        }
        i64 ans = 0;
        for (int i = 0; i < n; i++)
        {
            i64 temp;
            temp = mul * mi[a[i]];
            if (temp > mod)
                temp %= mod;
            temp *= (a[i] - 1);
            if (temp > mod)
                temp %= mod;
            ans += temp;
            //                        ans %= mod;
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}