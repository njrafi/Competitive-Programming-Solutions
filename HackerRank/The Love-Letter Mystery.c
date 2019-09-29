#include <stdio.h>
#include <string.h>

int palin(char a[])
{
        int i,j,count=0;
        for(i=0 , j=strlen(a)-1 ; i<j ; i++ , j--)
                if(a[i]>a[j])
                        count += a[i] - a[j];
                else
                        count += a[j] - a[i];
        return count;
}

int main()
{
        int t;
        char a[10005];
        scanf("%d\n", &t);
        while(t--)
        {
                gets(a);
                printf("%d\n", palin(a));
        }
        return 0;
}
