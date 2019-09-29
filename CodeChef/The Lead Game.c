#include <stdio.h>


int main()
{
    int N,p1,p2,t1=0,t2=0,lead,h_lead=0,w;
    scanf("%d", &N);
    while(N)
    {
        scanf("%d %d",&p1,&p2);
        t1 = t1 + p1;
        t2 = t2 + p2;
        if (t1>t2)
        {
            lead = t1 - t2;
            p1 = 1;
        }
        else
        {
            lead = t2 - t1;
            p1 = 2;
        }

        if(lead>h_lead)
        {
            h_lead = lead;
            w = p1;
        }
        N--;
    }
    printf("%d %d", w,h_lead);
    return 0;
}
