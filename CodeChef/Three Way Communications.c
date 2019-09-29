#include <stdio.h>


int main()

{
    int T,x1,x2,x3,y1,y2,y3,xy,yz,zx,R;
    scanf("%d", &T);
    while(T)
    {
        scanf("%d", &R);
        R = R*R;
        scanf("%d %d", &x1, &y1);
        scanf("%d %d", &x2, &y2);
        scanf("%d %d", &x3, &y3);
        xy = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        yz = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        zx = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        if(xy<=R&&yz<=R&&zx<=R)
        {
            printf("yes\n");
        }
        else if ((xy<=R&&yz<=R)||(yz<=R&&zx<=R)||(xy<=R&&zx<=R))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }

        T--;
    }
    return 0;
}
