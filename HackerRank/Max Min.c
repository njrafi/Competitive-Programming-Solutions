#include <stdio.h>
#include <stdlib.h>
#define big 1000000007

void heapsort(int array[], int n)
{
 int i,t;

 heapify(array,n);

 for(i=n-1 ; i>0 ; i--)
 {
  t = array[0];
  array[0] = array[i];
  array[i] = t;
  adjust(array,i);
 }
}


void heapify(int array[], int n)
{
 int item,i,j,k;

 for(k=1 ; k<n ; k++)
 {
  item = array[k];
  i = k;
  j = (i-1)/2;

  while( (i>0) && (item>array[j]) )
  {
   array[i] = array[j];
   i = j;
   j = (i-1)/2;
  }
  array[i] = item;
 }
}

void adjust(int array[], int n)
{
 int item,i,j;

 j = 0;
 item = array[j];
 i = 2*j+1;

  while(i<=n-1)
 {
  if(i+1 <= n-1)
   if(array[i] < array[i+1])
    i++;
  if(item < array[i])
  {
   array[j] = array[i];
   j = i;
   i = 2*j+1;
  }
  else
   break;
 }
 array[j] = item;
}

int main()
{
        int N,i,K,min=big,max,tem,*c,tem2;
        scanf("%d %d", &N, &K);
        c = (int*)malloc(N*sizeof(int));
        for(i=0;i<N;i++)
                scanf("%d", &c[i]);

        heapsort(c,N);

        for(i=0;i+K<N;i++)
                if(c[i+K-1]-c[i]<min)
                        min = c[i+K-1]-c[i];


        printf("%d", min);
        return 0;

}
