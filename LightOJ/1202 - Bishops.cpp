#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, r1, c1, r2, c2;
    bool b1, b2;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        b1 = 0;
        b2 = 0;
        cin >> r1 >> c1 >> r2 >> c2;
        if ((r1 % 2 && c1 % 2) || (r1 % 2 == 0 && c1 % 2 == 0))
            b1 = 1;
        if ((r2 % 2 && c2 % 2) || (r2 % 2 == 0 && c2 % 2 == 0))
            b2 = 1;
        printf("Case %d: ", i);
        if (b1 != b2)
        {
            cout << "impossible" << endl;
            continue;
        }
        if (abs(r1 - r2) == abs(c1 - c2))
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }
    return 0;
}
