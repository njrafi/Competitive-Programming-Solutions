#include <bits/stdc++.h>
using namespace std;
int f(int num)
{
    int res = 0, i = 0;
    while (num)
    {
        res += (num % 10) * pow(2, i++);
        num /= 10;
    }
    return res;
}
int main()
{
    int a, b, c, d, t, ab, bb, cb, db;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        scanf("%d.%d.%d.%d", &ab, &bb, &cb, &db);
        printf("Case %d: ", i);
        if (a == f(ab) && b == f(bb) && c == f(cb) && d == f(db))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
