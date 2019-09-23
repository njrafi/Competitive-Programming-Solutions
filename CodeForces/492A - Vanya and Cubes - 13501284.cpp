#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, res = 0;
    int yo[55];
    cin >> n;
    for (int i = 1; i <= 50; i++)
    {
        res += i * (i + 1) / 2;
        yo[i] = res;
    }
    for (int i = 1; i < 50; i++)
        if (n == yo[i])
        {
            cout << i << endl;
            return 0;
        }
        else if (n < yo[i])
        {
            cout << i - 1 << endl;
            return 0;
        }
    return 0;
}
