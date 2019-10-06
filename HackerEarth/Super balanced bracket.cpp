#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        
        int l = 0 , r = s.size() - 1;
        int ans = 0;
        
        while(l < r)
        {
           // cout << l << " " << r << endl;
            while(l < r && s[l] != '(')
                l++;
            while(l < r && s[r] != ')')
                r--;
                
            if( s[l] == '(' && s[r] == ')')
                ans += 2;
            l++;
            r--;
            
        }
        
        cout << ans << endl;
        
    }
}
