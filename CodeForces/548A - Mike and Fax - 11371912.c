#include <stdio.h>
#include <string.h>
int ispalin(char inp[])
{
    int i, j;
    for (i = 0, j = strlen(inp) - 1; i <= j; i++, j--)
        if (inp[i] != inp[j])
            return 0;
    return 1;
}
int main()
{
    int k, f, l, i, j;
    char inp[10005], tes[10005];
    gets(inp);
    scanf("%d", &k);
    if (strlen(inp) % k)
    {
        printf("NO\n");
        return 0;
    }
    k = strlen(inp) / k;
    for (f = 0, l = k - 1; inp[l]; f += k, l += k)
    {
        for (i = f, j = 0; i <= l; i++, j++)
            tes[j] = inp[i];
        tes[j] = '\0';
        if (!ispalin(tes))
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}