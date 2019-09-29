#include <stdio.h>

int main()
{
        char a[100005];
        int b[200] = {0};
        int i,count=0;
        gets(a);
        for(i=0;a[i];i++)
                b[a[i]]++;

        for(i='a';i<='z';i++)
                if(b[i]%2 && b[i])
                        count++;

        if(count>1)
                printf("NO");
        else
                printf("YES");

        return 0;
}
