#include <stdio.h>

int inv(int a[],int n)
{
        int i,j,count=0;
        for(i=0;i<n-1;i++)
                for(j=i+1;j<n;j++)
                        if(a[i]>a[j])
                                count++;

        return count;
}

int l_inv(int a[],int n)
{
        int i,count = 0;
        for(i=0;i<n-1;i++)
                if(a[i]>a[i+1])
                        count++;
        return count;
}

int main()
{

        int T,i,a[500],n;
        scanf("%d", &T);
        while(T--)
        {
                scanf("%d", &n);
                for(i=0;i<n;i++)
                        scanf("%d", &a[i]);

                if( inv(a,n)==l_inv(a,n))
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}
