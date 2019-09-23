#include <stdio.h>
int main()
{
    int i, tem, a[10] = {0};
    for (i = 0; i < 6; i++)
    {
        scanf("%d", &tem);
        a[tem]++;
    }
    for (i = 1; i < 10; i++)
        if (a[i] >= 4)
        {
            if (a[i] == 6)
            {
                printf("Elephant");
                return 0;
            }
            else if (a[i] == 5)
            {
                printf("Bear");
                return 0;
            }
            else
            {
                for (i = 1; i < 10; i++)
                    if (a[i] == 2)
                    {
                        printf("Elephant");
                        return 0;
                    }
                printf("Bear");
                return 0;
            }
        }
    printf("Alien");
    return 0;
}