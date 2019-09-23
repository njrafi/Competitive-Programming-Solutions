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
int main()
{
    int ans = 0;
    string s;
    cin >> s;
    For(i, s.size())
    {
        if (s[i] != 'P')
            ans++;
        i++;
        if (s[i] != 'E')
            ans++;
        i++;
        if (s[i] != 'R')
            ans++;
    }
    cout << ans << endl;
}