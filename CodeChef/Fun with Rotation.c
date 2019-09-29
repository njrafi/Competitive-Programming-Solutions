#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif


int read_int()
{
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}


int main()
{
        int n,m,i, a[100000], d , index = 0;;
        char r;

        scanf("%d %d", &n, &m);
        for(i=0;i<n;i++)
                a[i] = read_int();

       while(m--)
        {
                scanf("\n%c %d", &r, &d);


                if(r!='R')
                {
                        if(r=='A')
                                d = n - d ;

                        index += d;
                        if(index>n)
                                index -= n ;
                        else if(index==n)
                                index = 0;

                }


                else
                {
                        if(d-1+index>=n)
                        {
                                d = d -1 + index - n;
                                printf("%d\n", a[d]);
                        }
                       else
                        printf("%d\n", a[d-1+index]);
                }
        }

        return 0;

}
