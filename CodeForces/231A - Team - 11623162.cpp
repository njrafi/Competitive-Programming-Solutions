#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, index[1005] = {0}, cnt = 0, ans = 0, tem;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> tem;
            cnt += tem;
        }
        if (cnt >= 2)
            ans++;
    }
    cout << ans;
    return 0;
}