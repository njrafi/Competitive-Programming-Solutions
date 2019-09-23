#include <stdio.h>
#include <string.h>
int main()
{
    char in[4][110];
    int i, a, b, c, d, ans = 0;
    for (i = 0; i < 4; i++)
        gets(in[i]);
    a = strlen(in[0]) - 2;
    b = strlen(in[1]) - 2;
    c = strlen(in[2]) - 2;
    d = strlen(in[3]) - 2;
    i = 0;
    if ((a <= b / 2 && a <= c / 2 && a <= d / 2) || (a >= b * 2 && a >= c * 2 && a >= d * 2))
    {
        ans = 65;
        i++;
    }
    if ((b <= a / 2 && b <= c / 2 && b <= d / 2) || (b >= a * 2 && b >= c * 2 && b >= d * 2))
    {
        ans = 66;
        i++;
    }
    if ((c <= a / 2 && c <= b / 2 && c <= d / 2) || (c >= a * 2 && c >= b * 2 && c >= d * 2))
    {
        ans = 67;
        i++;
    }
    if ((d <= a / 2 && d <= b / 2 && d <= c / 2) || (d >= a * 2 && d >= b * 2 && d >= c * 2))
    {
        ans = 68;
        i++;
    }
    if (i == 1)
        printf("%c", ans);
    else
        printf("C");
    return 0;
}