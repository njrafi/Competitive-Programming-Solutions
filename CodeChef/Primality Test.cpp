#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pri priority_queue<int>
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

bool prime[100005];

void gen()
{
        For(i,100005)
                prime[i] = 1;
        prime[1] = 0;
        for(int i=2;i<=sqrt(100005);i++)
                if(prime[i])
                        for(int j=2*i;j<100005;j+=i)
                                prime[j] = 0;
}

int main()
{
        gen();
        int t,inp;
        cin >> t;
        while(t--)
        {
                cin >> inp;
                if(prime[inp])
                        cout << "yes";
                else
                        cout << "no";
                cout << endl;
        }



        return 0;
}

