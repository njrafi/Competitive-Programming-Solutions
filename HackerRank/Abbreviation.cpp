#include <bits/stdc++.h>

using namespace std;


string s1,s2;
int dp[1003][1003];
bool f(int lp,int rp)
{
    //cout << lp << " " << rp << endl;
    if(lp > s1.size() || rp > s2.size()) return false;
    if( lp == s1.size() && rp == s2.size()) return true;
    if ( dp[lp][rp] != -1) return dp[lp][rp];
    
    bool ans = 0;
    if(isupper(s1[lp])) {
        if(s1[lp] == s2[rp]) ans = max(ans , f(lp+1,rp+1));
    } else {
        int gg = toupper(s1[lp]);
        ans = max(ans , f(lp+1,rp));
        if(gg == s2[rp]) ans = max(ans , f(lp+1,rp+1));
    }

    return dp[lp][rp] = ans;

}


int main() {
    int t;
    cin >> t;

    while(t--)
    {
        cin >> s1 >> s2;
    
        memset(dp,-1,sizeof dp);
        if(f(0,0))
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
