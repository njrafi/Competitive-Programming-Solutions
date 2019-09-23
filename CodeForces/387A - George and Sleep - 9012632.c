#include <stdio.h>
int main()
{
    int h, h1, h2, m, m1, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    if (m1 >= m2)
        m = m1 - m2;
    else
    {
        m = m1 + 60 - m2;
        h2++;
    }
    h = (h1 + 24 - h2) % 24;
    if (h > 9)
        printf("%d:", h);
    else
        printf("0%d:", h);
    if (m > 9)
        printf("%d", m);
    else
        printf("0%d", m);
    return 0;
}