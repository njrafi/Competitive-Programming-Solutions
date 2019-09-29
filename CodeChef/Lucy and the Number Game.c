#include <stdio.h>
#include <string.h>

void heapsort(int array[],char names[][6], int n);
void heapify(int array[],char names[][6], int n);
void adjust(int array[],char names[][6], int n);


int main()
{
        int T,i,N, index[10000]  , min, min_pos;
        char names[10000][6] ;
        scanf("%d", &T);
        while(T--)
        {
                min = 0;
                scanf("%d", &N);
                for(i=0;i<N;i++)
                        scanf("%s %d", names[i], &index[i]);


                heapsort(index,names,N);

                for(i=0;i<N;i++)
                {
                        if(( i==0 || index[i]!=index[i-1] ) && ( index[i]!=index[i+1]  || i==N-1) )
                        {
                                min = index[i];
                                min_pos = i;
                                break;
                        }
                }

            if(!min)
                printf("Nobody wins.\n");
             else
                      printf("%s\n", names[min_pos]);

    //     for(i=0;i<N;i++)
      //         printf("%s %d\n",names[i], index[i]);


        }
        return 0;
}


void heapsort(int array[],char names[][6], int n)
{
 int i,t;
 char tem[6];
 heapify(array,names,n);

 for(i=n-1 ; i>0 ; i--)
 {
  t = array[0];
  array[0] = array[i];
  array[i] = t;


  strcpy(tem,names[0]);
  strcpy(names[0],names[i]);
  strcpy(names[i], tem);

  adjust(array,names,i);
 }
}


void heapify(int array[],char names[][6], int n)
{
 int item,i,j,k;
 char tem[6];

 for(k=1 ; k<n ; k++)
 {
  item = array[k];
  strcpy(tem,names[k]);
  i = k;
  j = (i-1)/2;

  while( (i>0) && (item>array[j]) )
  {
   array[i] = array[j];
   strcpy(names[i], names[j]);
   i = j;
   j = (i-1)/2;
  }
  array[i] = item;
  strcpy(names[i], tem);
 }
}

void adjust(int array[],char names[][6], int n)
{
 int item,i,j;
char tem[6];
 j = 0;
 item = array[j];
 strcpy(tem,names[j]);
 i = 2*j+1;

  while(i<=n-1)
 {
  if(i+1 <= n-1)
   if(array[i] < array[i+1])
    i++;
  if(item < array[i])
  {
   array[j] = array[i];
   strcpy(names[j], names[i]);
   j = i;
   i = 2*j+1;
  }
  else
   break;
 }
 array[j] = item;
 strcpy(names[j], tem);
}
