#include <stdio.h>


int main()
{
    int T,N;
    scanf("%d", &T);
    while(T)
    {
        scanf("%d", &N);
        if (360%N==0)
        {
            printf ("y ");
        }
        else
        {
            printf ("n ");
        }
        if (N<=360)
        {
            printf("y ");
        }
        else
        {
            printf ("n ");
        }
        if (N<=26)
        {
            printf("y\n");
        }
        else
        {
            printf ("n\n");
        }
        T--;
    }
    return 0;
}
