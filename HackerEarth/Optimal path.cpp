#include <bits/stdc++.h>
 
using namespace std;
#define i64 long long int
#define sz size()
#define infll LLONG_MAX/3
#define vi vector<int>
#define clr clear()
#define sf(n) scanf("%d" , &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define pb push_back
#define mxn 100005
 
int k;
vi v;
i64 dp[mxn];
 
i64 f(int pos)
{
    if(pos > v.sz) return infll;
    if(pos == v.sz - 1)
        return v[pos];
    if(dp[pos] != -1) return dp[pos];
    
    i64 ans = min(f(pos+1),f( pos + (pos+1) % k +1) ) + v[pos];
 
    return dp[pos] = ans;
    
}
 
 
int main() {
    int t,n,inp;
    sf(t);
    while(t--)
    {
        sff(n,k);
        v.clr;
        while(n--)
        {
            sf(inp);
            v.pb(inp);
        }
        memset(dp,-1,sizeof dp);
        cout << f(0) << endl;
    }
    
    
    
}
