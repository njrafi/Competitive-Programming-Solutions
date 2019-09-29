#include <stdio.h>

int main()
{
    int a[200],index,m,temp,x,n;


    int t,N;
    scanf("%d", &t); //test cases

    while(1)
    {
        scanf("%d", &N);
        a[0]=1,m=1;
        if (N==1)
        {
            printf("1");
        }
        else          // multiplying
        {
            temp=0;
            for(n=2;n<=N;n++)
            {


                for(index=0;index<m;index++)
                {
                    x = a[index]*n + temp;
                    a[index]= x%10;
                    temp = x/10;
                }

                while(temp!=0)
                {
                    m++;
                    a[index] = temp%10;
                    temp= temp/10;
                    index++;
                }
            }




            for(temp=m-1;temp>=0;temp--)
            {
                printf ("%d", a[temp]);
            }

        }
        t--;
        if (t==0)
        {
            break;
        }
        printf("\n");
    }

    return 0;
}
