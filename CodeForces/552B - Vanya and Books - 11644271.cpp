#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, ten = 10, sum = 0, i;
    cin >> n;
    for (i = 1; n > ten - 1; i++, ten *= 10)
        sum += (ten - ten / 10) * i;
    sum += (n - ten / 10 + 1) * i;
    cout << sum;
    return 0;
}