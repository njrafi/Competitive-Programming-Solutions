#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    float b,ls;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%f %f", &b,&ls);
        printf("%f %f\n", sqrt(ls*ls-b*b), sqrt(ls*ls+b*b));
    }
    return 0;
}
