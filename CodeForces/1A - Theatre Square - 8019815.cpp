#include <iostream>
using namespace std;
int main()
{
    long long int n; // long long int for large integers
    long long int m;
    long long int a;
    cin >> n;
    cin >> m;
    cin >> a;
    long long int tiles1 = n / a;
    long long int tiles2 = m / a;
    if (n % a != 0)
        tiles1++;
    if (m % a != 0)
        tiles2++;
    long long int result = tiles1 * tiles2;
    cout << result;
    return 0;
}