#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
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
        int t,i,a[100005],n;
        long long int count;
        fastRead(&t);
        while(t--)
        {
                count = 0;
                fastRead(&n);
                for(i=0;i<n;i++)
                        fastRead(&a[i]);

                heapsort(a,n);

                for(i=n-1;i>=0;i=i-2)
                        count += a[i];

                printf("%lld\n",count);

        }
        return 0;
}

