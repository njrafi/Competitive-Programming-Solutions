#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, tem;
    long long int inp, m, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> inp;
        tem = 0;
        printf("Case %d: ", i);
        if (inp % 2)
            cout << "Impossible" << endl;
        else
        {
            for (int j = 2; j <= inp / 2; j += 2)
                if (inp % j == 0 && (inp / j) % 2)
                {
                    tem++;
                    cout << inp / j << ' ' << j << endl;
                    break;
                }
            if (!tem)
                cout << "Impossible" << endl;
        }
    }
    return 0;
}
