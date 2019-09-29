#include <stdio.h>

int digit(int a)
{
        int count=0;
        while(a)
        {
                a /=10;
                count++;
        }
        return count;
}
int main()
{
        int r,c=50,i,j;
        scanf("%d\n", &r);
        char a[1005][52];
        for(i=0;i<r;i++)
                fgets(a[i],60,stdin);

        int b[52]={0};

        for(j=c-1;;j--)
        {
                for(i=0;i<r;i++)
                        b[j] += a[i][j]-'0';
                if(!j)
                        break;
                b[j-1]= b[j]/10;
                b[j] %= 10;
        }

        printf("%d", b[0]);
        for(i=1;i<=10-digit(b[0]);i++)
                printf("%d", b[i]);
        return 0;
}


