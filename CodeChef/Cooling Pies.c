#include <stdio.h>
void bubble(int index[], int num)
{
        int i,j,tem;

        for(i=0;i<num-1;i++)              // Number of times the loop will occur =num-1
                for(j=0;j<num-1-i;j++)          // number of element to check = num-i-1
                {
                        if(index[j]>index[j+1])         //swap the number if 1st one is larger than 2nd one
                        {
                                tem = index[j];
                                index[j] = index[j+1];
                                index[j+1] = tem;
                        }
                }

        // After each loop the (num-i)-th position will hold the largest number of the unsorted numbers

}
int main()


{
        int T,n,pies[30],w[30],i,tem,count,j;
        scanf("%d", &T);
        while(T--)
        {
                count = 0;
                scanf("%d", &n);
                for(i=0;i<n;i++)
                        scanf("%d", &pies[i]);
                for(i=0;i<n;i++)
                        scanf("%d", &w[i]);

                bubble(pies,n);
                bubble(w,n);
                for(i=0,j=0;i<n;i++)
                {
                        if(w[i]>=pies[j])
                        {
                                count++;
                                j++;
                        }
                }





                printf("%d\n",count);
        }
        return 0;
}
