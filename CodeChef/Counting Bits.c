#include <stdio.h>

int DtoB (int des)
{
        int count=0;
        while(des)
        {
                if(des%2)
                        count++;
                des /= 2;
        }
        return count;

}


int main()
{
        int T,i,N,sum;
        scanf("%d", &T);
        while(T--)
        {
                sum = 0;
                scanf("%d", &N);
                for(i=1;i<=N;i++)
                        sum += DtoB(i);
                printf("%d\n", sum);

        }
        return 0;
}
