#include <stdio.h>
#include <string.h>


int palindrome(long long int N)
{
        char digits[20];
        int i,j;
        for(i=0; N ; i++,N /=10)
                digits[i] = (N % 10) - '0';
        digits[i] = '\0';
        for(i=0,j=strlen(digits)-1; i<=j;i++,j--)
                if(digits[i]!=digits[j])
                        return 0;
        return 1;
}

int main()
{
        int i,j,count[2470],k=0;
        for(i=999;i>=100;i--)
                for(j=999;j>=100;j--)
                        if(palindrome(i*j))
                        {
                                count[k] = i*j;
                                k++;
                        }
       int t,max,N;
       scanf("%d", &t);
       while(t--)
       {
               max = 0;
               scanf("%d", &N);
               for(k=0;k<2470;k++)
                        if(count[k]>max && count[k]<N)
                                max = count[k];
                printf("%d\n", max);
       }
}
