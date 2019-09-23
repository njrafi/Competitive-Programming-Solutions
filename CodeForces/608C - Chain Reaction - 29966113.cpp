#include <iostream>
using namespace std;
const int maxn = 1e6 + 5;
int n, b[maxn], dp[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        cin >> b[a];
    }
    if (b[0] > 0)
    {
        dp[0] = 1;
    }
    int mx = 0;
    for (int i = 1; i < maxn; i++)
    {
        if (b[i] == 0)
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            if (b[i] >= i)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = dp[i - b[i] - 1] + 1;
            }
        }
        if (dp[i] > mx)
        {
            mx = dp[i];
        }
    }
    cout << n - mx << '\n';
    return 0;
}