#include <stdio.h>

int main()
{
        char a[110];
        int b[130] = {0};
        int i,N,j,count=0,t;
        scanf("%d\n", &N);
        t = N;
        while(t--)
        {
                fgets(a,105,stdin);
                for(i='a';i<='z';i++)
                        for(j=0;a[j];j++)
                                if(a[j]==i)
                                {
                                        b[a[j]]++;
                                        break;
                                }
        }

        for(i='a';i<='z';i++)
                if(b[i]==N)
                        count++;

        printf("%d" , count);
}
