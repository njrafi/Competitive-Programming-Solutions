#include <stdio.h>


int main()
{
    int T,a,b,t,count,uncle;
    int item[102];
    scanf("%d", &T);
    while(T)


    {

        scanf("%d", &count);
        for(a=0;a<count;a++)
        {
            scanf("%d", &item[a]);
        }
        scanf("%d", &b);

        uncle = item[b-1];

        //sorting
        for(a=0;a<count-1;a++)
        {
            for(b=a+1;b<count;b++)
            {
                if (item[a]>item[b])
                {
                    t = item [b];
                    item[b] = item [a];
                    item [a] = t;
                }
            }
        }
        for(a=0;a<count;a++)
        {
            if(item[a]==uncle)
            {
                t = a + 1;
                break;
            }
        }
        printf("%d\n", t);
        T--;

    }
    return 0;
}
