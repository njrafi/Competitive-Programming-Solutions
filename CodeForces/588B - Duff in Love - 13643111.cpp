#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define i64 long long
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
#define ff first
#define ss second
#define clr(a) memset(a, -1, sizeof(a))
#define rset(a) memset(a, 0, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("input.txt", "r", stdin)
#define max_e 1000000
map<long long int, int> m;
void primeFactors(i64 n)
{
    int i;
    while (n % 2 == 0)
    {
        m[2]++;
        n = n / 2;
    }
    for (i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            m[i] = 1;
            n = n / i;
        }
    }
    if (n > 2)
        m[n] = 1;
}
int main()
{
    i64 n, res, ans = 1;
    cin >> n;
    primeFactors(n);
    long long int i;
    map<long long int, int>::iterator mp;
    for (mp = m.begin(); mp != m.end(); mp++)
        ans *= mp->ff;
    cout << ans << endl;
    return 0;
}
