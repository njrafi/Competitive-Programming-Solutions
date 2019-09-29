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

vs v,ans;
string s,low;


void func()
{
        int start = 0, en = low.size(),mx = -1;
        string c;
        for(int i=start;i<en;i++)
                for(int j=i;j<en;j++)
        {
                int tem = 0;
                c = low.substr(i,j-i+1);
               // cout << c << endl;
                for(int k=0;k<v.size();k++)
                        if(v[k].find(c)==-1)
                        {
                                tem++;
                                break;
                        }
                if(!tem)
                {
                        //cout << "yo";
                        ans.pb(c);
                        tem = c.size();
                        if(tem>mx)
                                mx = tem;
                }
        }
       // cout << mx;
        for(int i=0;i<ans.size();i++)
                if(ans[i].size()<mx)
                {
                        ans.erase(ans.begin()+i);
                        i--;
                }
        sort(all(ans));
        cout << ans[0] << endl;

}
int main()
{

        int t,n,mx=30;
        cin >> t;
        while(t--)
        {
                cin >> n;
                v.clear();
                ans.clear();
                mx = 30;
                while(n--)
                {
                        cin >> s;
                        v.pb(s);
                        if(mx>s.size())
                        {
                                mx = s.size();
                                low = s;
                        }
                }
                func();
        }







/*        string s;
        cin >> s;
        string sub = s.substr(0,2);
        cout << sub; */


        return 0;
}

