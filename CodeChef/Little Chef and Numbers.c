#include <stdio.h>



int main()

{
        float T,i,N,c_o,c_t,c_z,num;
        scanf("%f", &T);

        while(T--)
        {
                c_o=0;
                c_t=0;
                c_z=0;
                scanf("%f", &N);
                for(i=0;i<N;i++)
                {
                        scanf("%f", &num);
                        if(num==1 ||num==0)
                                c_o++;
                        else if(num==2)
                                c_t++;
                }

                printf("%.0f\n",  ( N*(N-1)/2)  - c_o*N + c_o*c_o/2 + c_o/2  -  (c_t*(c_t-1) ) /2    );



        }
        return 0;
}
