#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, m;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        printf("Case %d: %lld\n", i, n * m / 2);
    }
    return 0;
}
