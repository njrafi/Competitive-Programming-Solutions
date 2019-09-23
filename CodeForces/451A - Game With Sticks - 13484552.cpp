#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
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
int main()
{
    int a, b;
    cin >> a >> b;
    if (min(a, b) % 2)
        cout << "Akshat";
    else
        cout << "Malvika";
    cout << endl;
    return 0;
}
