#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
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
#define rset(a) memset(a,0,sizeof(a))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)

//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
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

        int t,inp,n,tem;
        fastRead(&t);
        while(t--)
        {
                tem = 0;
                fastRead(&n);
                rev_pri p;
                vi v;
                v.pb(1000000009);
                for(int i=1;i<=n;i++)
                {
                        fastRead(&inp);
                        p.push(inp);
                        v.pb(inp);
                }
                v.pb(1000000009);/*
                for(int i=0;i<n+2;i++)
                        cout << v[i] << " ";
                        cout << endl;
                for(int i=0;i<n;i++)
                        {
                        cout << p.top() << " ";
                        p.pop();
                        } */
                for(int i=1;i<=n;i++)
                {

                        if(p.top()!=v[i] && p.top()!=v[i-1] && p.top()!=v[i+1])
                        {
                                tem++;
                                //cout << i <<" " <<p.top() << " " << v[i];
                                cout << "NO" << endl;
                                break;
                        }
                        p.pop();
                }
                if(!tem)
                        printf("YES\n");

        }



        return 0;
}

