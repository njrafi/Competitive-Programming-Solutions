#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif


inline void fastRead(int *a)
{
        register char c=0;
        while (c<33)
                c=gc();
        *a=0;
        while (c>33)
        {
                *a= *a*10+c-'0';
                c=gc();
        }
}


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
    int t,i,n,p,a[1005],b[1005],tem;
    fastRead(&t);
    while(t--)
    {
        fastRead(&n);
        fastRead(&p);
        for(i=1;i<=n;i++)
            a[i] = i;
        while(p--)
        {
            fastRead(&tem);
            a[tem] = 0;
        }
        p = 0;
        for(i=1;i<=n;i++)
            if(a[i])
            {
                b[p] = a[i];
                p++;
            }
        heapsort(b,p);
        for(i=0;i<p;i+=2)
            printf("%d ", b[i]);
        printf("\n");
        for(i=1;i<p;i+=2)
            printf("%d ", b[i]);
        printf("\n");
    }
    return 0;
}
