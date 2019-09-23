#include <bits/stdc++.h>
using namespace std;
long long int GCD(long long int m, long long int n)
{
    long long int r;
    while (1)
    {
        r = m % n;
        if (r == 0)
            break;
        m = n;
        n = r;
    }
    return n;
}
int main()
{
    long long int l, r;
    while (scanf("%I64d %I64d", &l, &r) != EOF)
    {
        long long int i, j, k;
        int tem = 0;
        for (i = l; i <= r; i++)
        {
            for (j = i + 1; j <= r; j++)
            {
                for (k = j + 1; k <= r; k++)
                {
                    if (GCD(i, j) == 1 && GCD(j, k) == 1 && GCD(i, k) != 1)
                    {
                        printf("%I64d %I64d %I64d\n", i, j, k);
                        tem++;
                        break;
                    }
                }
                if (tem)
                    break;
            }
            if (tem)
                break;
        }
        if (!tem)
            cout << -1 << endl;
    }
    return 0;
}
