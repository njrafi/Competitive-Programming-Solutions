#include <stdio.h>
#include <string.h>

int palin(char a[])
{
        int i,j;
        for(i=0,j=strlen(a)-1;i<j;i++,j--)
                if(a[i]!=a[j])
                        return 0;
        return 1;
}



int main()
{
        char p[100005];
        int T;
        scanf("%d\n", &T);
        while(T--)
        {
                gets(p);
                if(palin(p))
                        printf("1\n");
                else
                        printf("2\n");
        }
        return 0;
}
