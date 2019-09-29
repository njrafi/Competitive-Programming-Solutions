#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define i64 long long
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
#define eps 1e-8
#define ff first
#define ss second
#define clr(a) memset(a,-1,sizeof(a))
#define sz 5000005


#ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
#endif


inline void fastRead(int *a)
{
        register char c=0;
        while (c<33)
                c=gc();
        *a=0;
        while (c>33)
        {
                *a= *a*10+c-'0';
                c=gc();
        }
}

int main()
{

        bool calc[sz] = {0};
        int inp,t;
        for(int m=1;m<1581;m++)
                for(int n=m+1;m*m+n*n<sz;n++)
                        for(int k=1;k*(m*m+n*n)<sz;k++)
                                calc[k*(m*m+n*n)] = 1;

       fastRead(&t);
       while(t--)
       {
               fastRead(&inp);
               if(calc[inp])
                        puts("YES");
               else
                        puts("NO");
       }



        return 0;
}

