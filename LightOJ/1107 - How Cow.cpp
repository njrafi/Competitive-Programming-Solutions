#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, x, y, x1, x2, y1, y2, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        printf("Case %d:\n", i);
        while (n--)
        {
            cin >> x >> y;
            if (x > x1 && x < x2 && y > y1 && y < y2)
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
        }
    }
    return 0;
}
