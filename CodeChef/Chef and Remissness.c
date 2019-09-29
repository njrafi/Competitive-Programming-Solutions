#include <stdio.h>

int main()


{
    int T;
    unsigned long int A,B;
    scanf("%d", &T);

    while(T--)
    {
        scanf ("%lu %lu", &A,&B);
        if(A>=B)
        {
            printf("%lu %lu\n", A,A+B);
        }
        else
        {
            printf("%lu %lu\n", B,A+B);
        }
    }
    return 0;
}
