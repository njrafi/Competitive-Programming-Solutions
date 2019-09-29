#include <stdio.h>


int gra(int c[],int d[])
{
        int i;
        for(i='a';i<='z';i++)
                if(c[i]!=d[i])
                        return 0;

        return 1;
}

int gra_c(int c[],int d[])
{
        int i;
        for(i='a';i<='z';i++)
                if( (c[i] && !d[i] ) || (!c[i] && d[i] ) )
                   return 0;
        return 1;
}

int main()
{
        char a[1002],b[1002];
        int t,i;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%s %s", a,b);
                int c[128] = {0};
                int d[128] = {0};
                for(i=0;a[i];i++)
                        c[a[i]]++;
                for(i=0;b[i];i++)
                        d[b[i]]++;

                if(gra(c,d)==gra_c(c,d))
                        printf("YES\n");
                else
                        printf("NO\n");


        }
        return 0;

}
