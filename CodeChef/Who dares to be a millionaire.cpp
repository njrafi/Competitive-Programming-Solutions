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

int main()
{
        //freopen("in.txt","r",stdin);
        string s1,s2;
        vi w;
        int t,right,n,mx,inp;
        cin >> t;
        while(t--)
        {
                cin >> n >> s1 >> s2;
                right = 0;
                for(int i=0;i<s1.size();i++)
                        if(s1[i]==s2[i])
                                right++;
                w.clear();
                for(int i=0;i<=n;i++)
                {
                        cin >> inp;
                        w.pb(inp);
                }
                if(!right)
                        cout << w[0];
                else if(right==n)
                        cout << w[n];
                else
                {
                        mx = -1;
                        for(int i=0;i<=right;i++)
                                mx = max(mx,w[i]);
                        cout << mx;
                }
                cout << endl;
        }




        return 0;
}

