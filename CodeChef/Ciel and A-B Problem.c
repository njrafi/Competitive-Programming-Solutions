#include <stdio.h>

int main()

{
        int a,b,tem,diff;
        scanf("%d %d", &a, &b);
        diff = a - b;
        tem = diff % 10;
        tem++;
        tem %= 10;
        if(!tem)
                tem++;
        diff /= 10;
        if(diff)
                printf("%d",diff);
        printf("%d\n",tem);
        return 0;
}
