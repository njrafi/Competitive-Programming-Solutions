#include <bits/stdc++.h>
using namespace std;
long long int f(long long int row, long long int col, long long int ans)
{
    long long int tem = 0;
    for (long long int i = 1; i <= row; i++)
        tem += min(col, ans / i);
    // cout << "yo";
    return tem;
}
int main()
{
    long long int row, col, k;
    cin >> row >> col >> k;
    long long int low, high, ans;
    low = 1;
    high = row * col + 1;
    while (low < high)
    {
        ans = (low + high) / 2;
        if (f(row, col, ans) < k)
            low = ans + 1;
        else
            high = ans;
    }
    cout << low << endl;
    return 0;
}
