#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, in;
    cin >> t;
    while (t--)
    {
        cin >> in;
        if (in > 10)
            cout << 10 << ' ' << in - 10 << endl;
        else
            cout << in << ' ' << 0 << endl;
    }
    return 0;
}
