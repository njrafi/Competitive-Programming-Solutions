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
#define rset(a) memset(a,0,sizeof(a))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
typedef priority_queue<int,vector<int>,greater<int> > rev_pri;

int main()
{

        int t,n,inp,sum;
        cin >> t;
        while(t--)
        {
                cin >> n;
                rev_pri pq;
                while(n--)
                {
                        cin >> inp;
                        pq.push(inp);
                }
                sum = pq.top();
                pq.pop();
                sum += pq.top();
                cout << sum << endl;
        }


        return 0;
}

