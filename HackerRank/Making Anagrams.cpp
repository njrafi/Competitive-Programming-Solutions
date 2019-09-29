#include <bits/stdc++.h>
using namespace std;
int main()
{
        char a[10005],b[10005];
        int c[130], d[130],i,cou=0;
        scanf("%s %s",a,b);
        for(i=0;a[i];i++)
                c[a[i]]++;
        for(i=0;b[i];i++)
                d[b[i]]++;
        for(i=0;i<130;i++)
                cou += abs(c[i]-d[i]);
        printf("%d\n",cou);
        return 0;

}
