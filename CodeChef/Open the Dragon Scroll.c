#include <stdio.h>
#include <string.h>
#include <math.h>


int BtoD (char bin[])
{
        int i,des=0,lenth;
        int len = strlen(bin);
        for(i=0;bin[i];i++)
                if(bin[i]=='1')
                        des += pow(2,len-i-1);

        return des;
}

char binary[100];

void DtoB (int des)
{
        int i,j;
        int bin[100];
        for(i=0;des;i++)
        {
                bin[i] =  des%2;
                des /= 2;
        }

        for(i=i-1,j=0;i>=0;i--,j++)
        {
                if(bin[i]==1)
                        binary[j] = '1';
                else
                        binary[j] = '0';
        }

        binary[j] = '\0';

}


int main()

{
       int T,N,des1,des2,i,fin;
       char bin[31];
       scanf("%d", &T);
       while(T--)
       {
               int count1=0,count2=0;
               scanf("%d %d %d", &N, &des1, &des2);


               DtoB(des1);
               for(i=0;binary[i];i++)
                        if(binary[i]=='1')
                                count1++;

               DtoB(des2);
               for(i=0;binary[i];i++)
                        if(binary[i]=='1')
                                count2++;

                if( (count1+count2) <= N)
                        fin = count1 + count2;
                else
                        fin =  2*N -  (count1 + count2);


                for(i=0;i<fin;i++)
                        bin[i] = '1';
                for(;i<N;i++)
                        bin[i] = '0';

                bin[i] = '\0';

                printf("%d\n", BtoD(bin));


          //      printf("%d", count1 + count2);


       }

        return 0;
}


