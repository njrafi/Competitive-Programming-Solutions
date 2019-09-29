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

int dp[101][101],n,inp[101][101];

int func(int x,int y)
{
        if(x==n-1)
                return inp[x][y];
        if(dp[x][y]!=-1)
                return dp[x][y];
        return dp[x][y] =  inp[x][y] + max(func(x+1,y),func(x+1,y+1));
}



int main()
{

        int t;
        cin >> t;
        while(t--)
        {
                cin >> n;
                clr(dp);
                for(int i=0;i<n;i++)
                        for(int j=0;j<=i;j++)
                                cin >> inp[i][j];

                cout << func(0,0) << endl;
        }



        return 0;
}

