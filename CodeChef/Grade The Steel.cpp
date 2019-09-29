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


int main()
{
        int t;
        double a,b,c;
        cin >> t;
        while(t--)
        {
                cin >> a >> b >> c;
                if(a>50)
                        a = 1;
                else
                        a = 0;
                if(b<0.7)
                        b = 1;
                else
                        b = 0;
                if(c>5600)
                        c = 1;
                else
                        c = 0;
                if(a&&b&&c)
                        cout << 10;
                else if(a&&b)
                        cout << 9;
                else if(b&&c)
                        cout << 8;
                else if(c&&a)
                        cout << 7;
                else if(a||b||c)
                        cout << 6;
                else
                        cout << 5;
                cout << endl;
        }




        return 0;
}

