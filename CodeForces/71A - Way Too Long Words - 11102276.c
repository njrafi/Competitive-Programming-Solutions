#include <stdio.h>
#include <string.h>
int main()
{
    int n, i, len;
    char word[105];
    scanf("%d\n", &n);
    while (n--)
    {
        gets(word);
        len = strlen(word);
        if (len <= 10)
        {
            puts(word);
            continue;
        }
        printf("%c%d%c\n", word[0], len - 2, word[len - 1]);
    }
    return 0;
}