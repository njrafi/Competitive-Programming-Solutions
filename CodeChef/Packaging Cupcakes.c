#include <stdio.h>

int main()



{
    int t;
    unsigned long int N;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%lu", &N);
        printf ("%lu\n", N/2+1);
    }

    return 0;
}
