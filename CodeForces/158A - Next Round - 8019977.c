#include <stdio.h>
int main()
{
    int n, k, i, count = 0, tem, t;
    scanf("%d %d", &n, &k);
    t = k;
    while (t--)
    {
        scanf("%d", &tem);
        if (tem)
            count++;
        else
            break;
    }
    if (count < k)
    {
        printf("%d", count);
        return 0;
    }
    for (i = 1; i <= n - k; i++)
    {
        scanf("%d", &t);
        if (t == tem)
            count++;
        else
            break;
        tem = t;
    }
    printf("%d", count);
    return 0;
}