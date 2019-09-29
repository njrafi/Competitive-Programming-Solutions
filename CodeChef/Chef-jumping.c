#include <stdio.h>

int main()
{
        long long int i;
        scanf("%lld", &i);
        i %= 6;
        if(i==0 || i==1 || i==3)
                printf("yes");
        else
                printf("no");
        return 0;
}
