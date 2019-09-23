#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pri priority_queue<int>
#define rev_pri priority_queue<int, vector<int>, greater<int>>
#define mpi map<int, int>
#define i64 long long int
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
#define sz size()
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int diff = 0;
    For(i, s1.sz) if (s1[i] != s2[i])
        diff++;
    // cout << diff ;
    if (diff % 2)
    {
        cout << "impossible";
        return 0;
    }
    diff /= 2;
    For(i, s1.sz)
    {
        if (s1[i] != s2[i])
        {
            if (diff)
            {
                diff--;
                cout << s1[i];
            }
            else
                cout << s2[i];
        }
        else
            cout << s2[i];
    }
    cout << endl;
    return 0;
}
