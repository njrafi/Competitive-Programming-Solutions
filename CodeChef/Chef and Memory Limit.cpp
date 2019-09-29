#include <bits/stdc++.h>

using namespace std;
int main()
{
        long long int t,current,n,i,tem,ans;
        cin >> t;
        while(t--)
        {
                ans = 0;
                cin >> n;
                cin >> current;
                ans += current;
                for(i=1;i<n;i++)
                {
                        cin >> tem;
                        if(tem>current)
                                ans += tem-current;
                        current = tem;
                }
                cout << ans << endl;
        }
        return 0;
}
