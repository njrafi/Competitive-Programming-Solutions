#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef vector<int> vi;
typedef set<int> si;
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mod 1e9 + 7
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
int main()
{
    int n, t;
    cin >> n >> t;
    if (t != 10)
        while (n--)
            cout << t;
    else if (n == 1)
        cout << -1;
    else
    {
        cout << 1;
        n--;
        while (n--)
            cout << 0;
    }
    cout << endl;
    return 0;
}
