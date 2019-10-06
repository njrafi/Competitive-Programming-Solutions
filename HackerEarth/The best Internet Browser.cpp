#include <bits/stdc++.h>
using namespace std;
 
bool f(char c)
{
 if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
  return 1;
 return 0;
 
}
int main()
{
    int t;
    string s;
    cin >> t;
    while(t--)
    {
     cin >> s;
     int ans = 0;
     for(int i=4; i<s.size()-4;i++)
      if(!f(s[i]))
       ans++;
   cout << ans+4 << '/' << s.size() << endl;
    }
    return 0;
}
