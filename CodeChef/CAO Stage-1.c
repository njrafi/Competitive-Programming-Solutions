#include <stdio.h>

int up(char a[51][51],int i,int j)
{
    int count= 0,k;

    for(k=i-1;k>i-3;k--)
                if(a[k][j]=='^')
                        count++;
   return count;
}

int right(char a[51][51],int i,int j)
{
    int count= 0,k;

    for(k=j+1;k<j+3;k++)
                if(a[i][k]=='^')
                        count++;
   return count;
}

int down(char a[51][51],int i,int j)
{
    int count= 0,k;

    for(k=i+1;k<i+3;k++)
                if(a[k][j]=='^')
                        count++;
   return count;
}

int left(char a[51][51],int i,int j)
{
    int count= 0,k;

    for(k=j-1;k>j-3;k--)
                if(a[i][k]=='^')
                        count++;
   return count;
}


int main()
{
        char a[51][51];
        int t,i,j,r,c,count;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d %d\n", &r, &c);
                count = 0;
                for(i=0;i<r;i++)
                        gets(a[i]);

                for(i=2;i<r-2;i++)
                        for(j=2;j<c-2;j++)
                        {
                                if(a[i][j]!='^')
                                        continue;
                                if(up(a,i,j)<2)
                                        continue;
                                if(down(a,i,j)<2)
                                        continue;
                                if(left(a,i,j)<2)
                                        continue;
                                if(right(a,i,j)<2)
                                        continue;
                                count++;

                        }
                printf("%d\n", count);
        }
        return 0;
}
