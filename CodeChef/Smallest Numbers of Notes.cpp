#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
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
#define set(a) memset(a,0,sizeof(a))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)



int main()
{

        int t,n,ans;
        cin >> t;
        while(t--)
        {
                ans = 0;
                cin >> n;
                ans += n/100;
                n %= 100;
                ans += n/50;
                n %= 50;
                ans += n/10;
                n %= 10;
                ans += n/5;
                n %= 5;
                ans += n/2;
                n %= 2;
                ans += n;
                cout << ans <<endl;
        }



        return 0;
}

