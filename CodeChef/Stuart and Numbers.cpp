#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define si set<int>
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

int main()
{
        int t,n,x,indx,mx,tem;
        vector<string> v;
        string inp;
        cin >> t;
        while(t--)
        {
              v.clear();
              cin >> n;
              while(n--)
              {
                      cin >> inp;
                      v.pb(inp);
              }
              cin >> x;
              x += '0';
              mx = 0;
              for(int i=0;i<v.size();i++)
                {
                        tem = 0;
                        for(int j=0;j<v[i].size();j++)
                                        if(v[i][j]==x)
                                                tem++;
                        if(tem>mx)
                        {
                                mx = tem;
                                indx = i;
                        }
                }
                cout << v[indx] << endl;
        }





        return 0;
}

