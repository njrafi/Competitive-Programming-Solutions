#include <stdio.h>
#include <ctype.h>
int main()
{
    int i, j;
    char a[105], out[300];
    gets(a);
    for (i = 0; a[i]; i++)
        a[i] = tolower(a[i]);
    for (i = 0, j = 0; a[i]; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'y')
            continue;
        out[j] = '.';
        j++;
        out[j] = a[i];
        j++;
    }
    out[j] = '\0';
    puts(out);
    return 0;
}