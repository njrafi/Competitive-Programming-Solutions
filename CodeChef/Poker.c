#include <stdio.h>

void bubble(int index[],char suit[] ,int num)
{
        int i,j,tem;

        for(i=0;i<num-1;i++)
                for(j=0;j<num-i-1;j++)
                {
                        if(index[j]>index[j+1])
                        {
                                tem = index[j];
                                index[j] = index[j+1];
                                index[j+1] = tem;
                                tem = suit[j];
                                suit[j] = suit[j+1];
                                suit[j+1] = tem;
                        }
                }
}

int straight(int a[])
{
        int b[5];
        if(a[0]==a[1]-1  && a[1]==a[2]-1  && a[2]==a[3]-1  && a[3]==a[4]-1)
                return 1;
        else
        {
                if(a[4]==14)
                {
                        b[0] = 1;
                        b[1] = a[0];
                        b[2] = a[1];
                        b[3] = a[2];
                        b[4] = a[3];

                        if(b[0]==b[1]-1  && b[1]==b[2]-1  && b[2]==b[3]-1  && b[3]==b[4]-1)
                                return 1;
                        else
                                return 0;
                }
                return 0;
        }


}

int flush(char s[])
{
        if(s[0]==s[1] && s[1]==s[2] && s[2]==s[3] && s[3]==s[4])
                return 1;
        else
                return 0;
}

int four(int a[])
{
        if((a[0]==a[1] && a[1]==a[2] && a[2]==a[3]) || (a[1]==a[2] && a[2]==a[3] && a[3]==a[4]) )
                return 1;
        else
                return 0;
}

int three(int a[])
{
        if(  (a[0]==a[1] && a[1]==a[2]) || (a[1]==a[2] && a[2]==a[3]) ||  (a[2]==a[3] && a[3]==a[4]) )
                return 1;
        else
                return 0;
}

int pair(int a[])
{
        int count=0,i;
        for(i=0;i<4;i++)
        {
                if(a[i]==a[i+1])
                        count++;
        }
        if (three(a))
                return count - 2;
        else if (four(a))
                return count - 3;
        else
                return count;

}


int main()

{
        char suit[5],tem[15] ;
        int rank[5];
        int T,i,j;
        scanf("%d", &T);
        while(T--)
        {
                //inputting
                scanf("\n");
                fgets(tem,15,stdin);
                for(i=0,j=0;i<15;i=i+3,j++)
                {
                        switch(tem[i])
                        {
                                case 'T':
                                        rank[j] = 10;
                                        break;
                                case 'J':
                                        rank[j] = 11;
                                        break;
                                case 'Q':
                                        rank[j] = 12;
                                        break;
                                case 'K':
                                        rank[j] = 13;
                                        break;
                                case 'A':
                                        rank[j] =14;
                                        break;
                                default:
                                        rank[j] = (int)(tem[i] - '0') ;
                                        break;
                        }

                        suit[j] = tem[i+1];
                }

                bubble(rank,suit,5);

            //    for(i=0;i<5;i++)
             //   {
             //           printf("%d", rank[i]);
             //           printf("%c", suit[i]);
             //           printf("\n");
             //   }


                if(straight(rank)==1 && flush(suit)==1 && rank[0]==10)
                        printf("royal flush\n");
                else if(straight(rank)==1 && flush(suit)==1)
                        printf("straight flush\n");
                else if(four(rank)==1)
                        printf("four of a kind\n");
                else if(three(rank)==1 && pair(rank)==1)
                        printf("full house\n");
                else if(flush(suit)==1)
                        printf("flush\n");
                else if(straight(rank)==1)
                        printf("straight\n");
                else if(three(rank)==1)
                        printf("three of a kind\n");
                else if(pair(rank)==2)
                        printf("two pairs\n");
                else if(pair(rank)==1)
                        printf("pair\n");
                else
                        printf("high card\n");


        }
        return 0;

}
