#include <stdio.h>
     
int main() 
{
    int num,t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&num);
    if ( num%2==0 )
    	printf("%d\n",num);
    else
    	printf("%d\n",num-1);
    }
    return 0;
} 