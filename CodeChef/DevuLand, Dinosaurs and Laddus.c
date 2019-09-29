#include <stdio.h>

int max(int x,int y)
{
        if(x>=y)
                return x;
        else
                return y;
}

int min(int x,int y)
{
        if(x<y)
                return x;
        else
                return y;
}

int main()
{
        int n_v[100005],p_v[100005], n_d[100005], p_d[100005],i,j,k,tem,t,num_vi,num_di,n;
        long long int count;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &n);
                k = 0;
                j = 0;
                count = 0;
                for(i=1;i<=n;i++)
                {
                        scanf("%d", &tem);
                        if(tem>0)
                        {
                                n_v[j] = tem;
                                p_v[j] = i;
                                j++;
                        }
                        else if(tem<0)
                        {
                                n_d[k] = -tem;
                                p_d[k] = i;
                                k++;
                        }
                }
                num_vi = j;
                num_di = k;
                for(i=0;i<num_di;i++)
                        for(j=0;j<num_vi;j++)
                        {
                                if(!n_d[i])
                                        break;
                                if(!n_v[j])
                                        continue;

                                if(n_d[i]==n_v[j])
                                {
                                        count += n_v[j] * (max(p_d[i],p_v[j]) - min(p_d[i],p_v[j]));
                                        n_d[i] = 0;
                                        n_v[j] = 0;
                                }
                                else if(n_d[i]<n_v[j])
                                {
                                        count += n_d[i] * (max(p_d[i],p_v[j]) - min(p_d[i],p_v[j])) ;
                                        n_v[j] -= n_d[i];
                                        break;
                                }
                                else if(n_d[i]>n_v[j])
                                {
                                       count += n_v[j] * (max(p_d[i],p_v[j]) - min(p_d[i],p_v[j])) ;
                                       n_d[i] -= n_v[j];
                                       n_v[j] = 0;
                                }

                        }
                printf("%lld\n", count);
        }
        return 0;
}
