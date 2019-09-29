#include <stdio.h>

int main()
{
        int x,y,z,c;
        while(1)
        {
                scanf("%d %d %d", &x,&y,&z);
                if(x==0 && y==0 && z==0)
                        break;
                else if((float)z/y == (float)y/x)
                        printf("GP %d\n", z*z/y);
                else
                        printf("AP %d\n", 2*z-y);
        }
        return 0;
}
