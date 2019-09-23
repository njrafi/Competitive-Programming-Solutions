#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll x, n, a[1010] = {0};
        scanf("%lld %lld", &x, &n);
        if (n == 1)
        {
            printf("%lld\n", x);
            continue;
        }
        ll turn = x / (n - 1);
        //        cout << turn << endl;
        if (turn & 1)
        {
            a[0] = turn / 2 + 1;
            a[n - 1] = turn / 2;
            for (int i = 1; i < n - 1; i++)
                a[i] = turn;
            ll rem = x % (n - 1);
            for (int i = n - 1; i >= 0 && rem; i--, rem--)
                a[i]++;
        }
        else
        {
            a[0] = turn / 2;
            a[n - 1] = turn / 2;
            for (int i = 1; i < n - 1; i++)
                a[i] = turn;
            ll rem = x % (n - 1);
            for (int i = 0; i < n && rem; i++, rem--)
                a[i]++;
        }
        //        cout << "BUG" << endl;
        printf("%lld", a[0]);
        for (int i = 1; i < n; i++)
            printf(" %lld", a[i]);
        printf("\n");
    }
}