#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
        int T,i,j,tem,count;
        char m[25010], w[25010];
        scanf("%d", &T);

        while(T--)
        {
                scanf("%s %s", m,w);
                count= 0;
                if(strlen(m)<=strlen(w))
                {

                        j = 0;
                        for(i=0;m[i];i++)
                        {
                                tem = 0;
                                for(;w[j];j++)
                                {
                                        if(m[i]==w[j])
                                        {
                                                w[j] = toupper(w[j]);
                                                tem ++;
                                                break;
                                        }
                                }
                                if(!tem)
                                {
                                        count++;
                                        break ;
                                }
                        }
                }

                else
                {
                        j = 0;
                        for(i=0;w[i];i++)
                        {
                                tem = 0;
                                for(;m[j];j++)
                                {
                                        if(w[i]==m[j])
                                        {
                                                m[j] = toupper(m[j]);
                                                tem ++;
                                                break;
                                        }
                                }

                                if(!tem)
                                {
                                        count++;
                                        break ;
                                }
                        }
                }


                if( !count)
                        printf("YES\n");
                else
                        printf("NO\n");
        }
        return 0;
}
