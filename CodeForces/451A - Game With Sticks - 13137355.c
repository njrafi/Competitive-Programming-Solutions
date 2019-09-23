#include <stdio.h>
int main()
{
    int n, m, low;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (m <= n)
            low = m;
        else
            low = n;
        if (low % 2)
            printf("Akshat\n");
        else
            printf("Malvika\n");
    }
    return 0;
}