#include <bits/stdc++.h>
#define LIM 100005
using namespace std;
int n, a[LIM], x, p = -1, q = -1;
int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        if (a[i] < x)
        {
            p = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (a[i] > x)
        {
            q = i;
            break;
        }
    if (p != -1 && q != -1)
        cout << 2 << endl;
    else
        cout << -1 << endl;
}