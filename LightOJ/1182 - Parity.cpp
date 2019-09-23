#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, inp;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        printf("Case %d: ", i);
        cin >> inp;
        inp = __builtin_popcount(inp);
        if (inp % 2)
            cout << "odd";
        else
            cout << "even";
        cout << endl;
    }
    return 0;
}
