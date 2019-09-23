#include <stdio.h>
int main()
{
    char a[] = "qwertyuiopasdfghjkl;zxcvbnm,./QWERTYUIOPASDFGHJKL;ZXCVBNM,./", tem, b[105];
    int i, j;
    scanf("%c\n", &tem);
    gets(b);
    if (tem == 'L')
    {
        for (i = 0; b[i]; i++)
        {
            for (j = 0; a[j]; j++)
            {
                if (b[i] == a[j])
                {
                    printf("%c", a[j + 1]);
                    break;
                }
            }
        }
    }
    else if (tem == 'R')
        for (i = 0; b[i]; i++)
            for (j = 0; a[j]; j++)
                if (b[i] == a[j])
                {
                    printf("%c", a[j - 1]);
                    break;
                }
    return 0;
}