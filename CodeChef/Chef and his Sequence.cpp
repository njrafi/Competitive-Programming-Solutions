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
        vi v1,v2;
        int n,t,inp,i,j;
        cin >> t;
        while(t--)
        {
                cin >> n;
                v1.clear();
                v2.clear();
                while(n--)
                {
                        cin >> inp;
                        v1.pb(inp);
                }
                cin >> n;
                while(n--)
                {
                        cin >> inp;
                        v2.pb(inp);
                }
                for(i=0,j=0;i<v1.size() && j<v2.size();i++)
                        if(v1[i]==v2[j])
                                j++;
                if(j<v2.size())
                        cout << "No";
                else
                        cout << "Yes";
                cout << endl;
        }




        return 0;
}

