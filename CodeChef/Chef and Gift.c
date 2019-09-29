#include <stdio.h>


int main()

{
        int T,n,k, a[50];
        int i,count;
        scanf("%d", &T);
        while(T--)
        {
                count = 0;
                scanf("%d %d", &n,&k);
                for(i=0;i<n;i++)
                {
                        scanf("%d", &a[i]);
                        if(a[i]%2==0)
                                count++;
                }

           //;  if(a[0]%2==0 && a[n-1]%2==0)
              //          count--;

                if((count>=k && k>0) ||(k==0 && count<n) )
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}
