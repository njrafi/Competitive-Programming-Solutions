#include <bits/stdc++.h>
#define pi 2 * acos(0)
using namespace std;
int main()
{
    int t;
    double r;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> r;
        printf("Case %d: %.2f\n", i, r * r * (4 - pi));
    }
    return 0;
}
