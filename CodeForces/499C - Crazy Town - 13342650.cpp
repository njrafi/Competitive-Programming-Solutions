#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b, c, x1, y1, x2, y2, v1, v2;
    int n, res = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        v1 = x1 * a + y1 * b + c;
        v2 = x2 * a + y2 * b + c;
        if ((v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0))
            res++;
    }
    cout << res << endl;
    return 0;
}
