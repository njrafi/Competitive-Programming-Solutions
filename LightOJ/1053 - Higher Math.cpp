#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, s[3];
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> s[0] >> s[1] >> s[2];
        sort(s, s + 3);
        printf("Case %d: ", i);
        if (s[2] * s[2] == s[0] * s[0] + s[1] * s[1])
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}
