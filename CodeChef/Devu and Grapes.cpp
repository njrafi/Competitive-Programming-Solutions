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

        i64 t,n,k,ans,inp;
        cin >> t;
        while(t--)
        {
                ans = 0;
                cin >> n >> k;
                while(n--)
                {
                        cin >> inp;
                        if(inp<k)
                                ans += k-inp;
                        else
                        {
                                inp = inp%k;
                                ans += min(k-inp,inp);
                        }
                }
                cout << ans << endl;
        }



        return 0;
}
