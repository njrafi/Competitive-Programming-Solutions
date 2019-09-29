#include <stdio.h>
#include <string.h>



int main()
{

        char s[100005], a[] = "010", b[] = "101";
        int t;
        scanf("%d\n", &t);
        while(t--)
        {
                gets(s);
                if(strstr(s,a) || strstr(s,b))
                        printf("Good\n");
                else
                        printf("Bad\n");

        }
}
