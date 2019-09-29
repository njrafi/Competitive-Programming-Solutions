#include <bits/stdc++.h>


using namespace std;

#define mxn 100005

vector<int> v;

int dp[mxn];

int f(int pos)
{
    if(pos >= v.size()) return 0;
    if(dp[pos] != -1) return dp[pos];

    int ans = f(pos+1);
    ans = max(ans,v[pos] + f(pos+2));

    return dp[pos] = ans;
}


int main() {

    int n,inp;
    cin >> n;
    while(n--)
    {
        cin >> inp;
        v.push_back(inp);
    }
    memset(dp,-1,sizeof dp);

    cout << f(0) << endl;

}
