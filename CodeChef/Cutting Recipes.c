#include <stdio.h>
#include <stdlib.h>


void recipe(int inp[],int n)

{
        int low = 10001,i,j,tem;
        for(i=0;i<n;i++)
                if(inp[i]<low)
                        low = inp[i];
        for(i=2;i<=low;)
        {
                tem = 0;
                for(j=0;j<n;j++)
                        if(inp[j]%i)
                                break;
                        else
                                tem++;
                if(tem == n)
                        for(j=0;j<n;j++)
                                inp[j] /= i;
                else
                        i++;
        }
        for(j=0;j<n;j++)
                printf("%d ",inp[j]);
        printf("\n");

}

int main()
{
        int t,*inp,i,n;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &n);
                inp = malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                        scanf("%d", &inp[i]);
                recipe(inp,n);
        }
        return 0;
}


