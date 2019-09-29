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

        int t,n,flag;
        string s;
        cin >> t;
        while(t--)
        {
                flag  = 0;
                cin >> n >> s;
                For(i,s.size())
                {
                        if(s[i]=='Y')
                        {
                                cout << "NOT INDIAN";
                                flag = 1;
                                break;
                        }
                        else if(s[i]=='I')
                        {
                                cout << "INDIAN";
                                flag = 1;
                                break;
                        }
                }
                if(!flag)
                        cout << "NOT SURE";
                cout << endl;
        }



        return 0;
}

