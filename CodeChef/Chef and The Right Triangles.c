#include <stdio.h>


int main()
{
    int x1,x2,x3,y1,y2,y3,ab,bc,ca;
    long int N,count=0;
    scanf("%li", &N);
    while(N)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        ab = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        bc = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        ca = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        if(ab==bc+ca||bc==ab+ca||ca==ab+bc)
        {
            count++;
        }
        N--;
    }
    printf("%d", count);
    return 0;
}
