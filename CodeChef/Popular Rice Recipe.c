#include <stdio.h>
#include <string.h>

int main()
{
        int t,n,vote[105],i,j,count;
        char v,user[105][25];
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &n);
                count = 0;
                for(i=0;i<n;i++)
                {
                        scanf("%s %c", user[i],&v);
                        if(v=='+')
                                vote[i] = 1;
                        else
                                vote[i] = -1;

                        for(j=0;j<i;j++)
                                if(!strcmp(user[i],user[j]))
                                        vote[j] = 0;
                }
                for(i=0;i<n;i++)
                        count += vote[i];

                printf("%d\n", count);

        }
        return 0;
}
