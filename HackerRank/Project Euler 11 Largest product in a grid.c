#include <stdio.h>

long long int up(int i,int j,int n,int a[][20])
{
        long long int ans=1;
        while(n--)
        {
                ans *= a[i][j];
                i++;
        }
        return ans;
}

long long int left(int i,int j,int n,int a[][20])
{
        long long int ans=1;
        while(n--)
        {
                ans *= a[i][j];
                j++;
        }
        return ans;
}

long long int dia_l(int i,int j,int n,int a[][20])
{
        long long int ans=1;
        while(n--)
        {
                ans *= a[i][j];
                i++;
                j++;
        }
        return ans;
}

long long int dia_r(int i,int j,int n,int a[][20])
{
        long long int ans=1;
        while(n--)
        {
                ans *= a[i][j];
                i++;
                j--;
        }
        return ans;
}



int main()
{
        int m[20][20], row=20, col=20, i,j,n=4;
        long long int max=0;


        for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                        scanf("%d", &m[i][j]);



        for(i=0;i+n<=row;i++)
                for(j=0;j<col;j++)
                        if(up(i,j,n,m)>max)
                                max = up(i,j,n,m);
      //  printf("%lld\n", max);

        for(i=0;i<row;i++)
                for(j=0;j+n<=col;j++)
                        if(left(i,j,n,m)>max)
                                max = left(i,j,n,m);
      // printf("%lld\n", max);

        for(i=0;i+n<=row;i++)
                for(j=0;j+n<=col;j++)
                        if(dia_l(i,j,n,m)>max)
                                max = dia_l(i,j,n,m);
     //   printf("%lld\n", max);

        for(i=0;i+n<=row;i++)
                for(j=n-1;j<col;j++)
                        if(dia_r(i,j,n,m)>max)
                                max = dia_r(i,j,n,m);

        printf("%lld\n", max);




}
