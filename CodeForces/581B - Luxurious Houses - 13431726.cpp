#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, inp, house[100005], ans[100005], m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> house[i];
    m = house[n - 1];
    ans[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (house[i] > m)
        {
            m = house[i];
            ans[i] = 0;
        }
        else
            ans[i] = m + 1 - house[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
