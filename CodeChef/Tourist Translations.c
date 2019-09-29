#include <stdio.h>

int main()
{
    int T,i,j;
    char byte[54],sentence[101], tem;
    char eng[54] = "abcdefghijklmnopqrstuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf ("%d %s", &T, &byte);
    byte[26] = ' ';
    for(i=27;i<=53;i++)
    {
        byte[i] = toupper(byte[i-27]);
    }
    // printf("%s", byte);
    while(T)
    {
        scanf("%s", &sentence);
        for(i=0;sentence[i];i++)
        {
            for(j=0;j<=53;j++)
            {
                if (sentence[i]==eng[j])
                {
                    sentence[i] = byte[j];
                    break;
                }
            }
        }
        printf("%s\n", sentence);
        T--;
    }
    return 0;
}
