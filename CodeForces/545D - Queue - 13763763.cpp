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
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
#define gc getchar
#define pc putchar
inline void fastRead(int *a)
{
    register char c = 0;
    while (c < 33)
        c = gc();
    *a = 0;
    while (c > 33)
    {
        *a = *a * 10 + c - '0';
        c = gc();
    }
}
inline void fastWrite(int a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc('\n');
}
int main()
{
    rev_pri p;
    i64 s = 0, d2 = 0;
    int n, inp;
    fastRead(&n);
    For(i, n)
    {
        fastRead(&inp);
        p.push(inp);
    }
    while (!p.empty())
    {
        if (s > p.top())
            d2++;
        else
            s += p.top();
        p.pop();
    }
    fastWrite(n - d2);
    return 0;
}
