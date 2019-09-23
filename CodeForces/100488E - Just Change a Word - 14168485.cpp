#include <bits/stdc++.h>
using namespace std;
int alpha[26];
int main()
{
    string s;
    cin >> s;
    memset(alpha, 0, sizeof(alpha));
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        alpha[s[i] - 'a']++;
    }
    int mx = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        mx = max(mx, alpha[i]);
    }
    if (len % 2)
        cout << "NO" << endl;
    else
    {
        if ((len - mx) >= mx)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}