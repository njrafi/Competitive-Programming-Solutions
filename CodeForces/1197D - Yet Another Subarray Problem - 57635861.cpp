#include <bits/stdc++.h>
using namespace std;
/*
7 3 10
2 -4 15 -3 4 8 3
*/
#define i64 long long int
int m, k;
i64 f(vector<int> v)
{
    multiset<i64> s;
    i64 offset = 0;
    i64 now = 0;
    for (int i = 0; i < v.size(); i++)
    {
        now += v[i];
        if (i % m == 0)
            offset += k;
        s.insert(now - offset);
    }
    i64 mx = 0;
    offset = 0;
    now = 0;
    i64 extra = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i % m == 0)
        {
            extra = now;
            offset += k;
        }
        now += v[i];
        auto it = s.end();
        it--;
        mx = max(mx, *it + offset - k - extra);
        //        cout << now - offset << " " << *it << " " << *it + offset - k << endl;
        s.erase(s.find(now - offset));
    }
    return mx;
}
int main()
{
    int n, inp;
    vector<int> v;
    cin >> n >> m >> k;
    while (n--)
    {
        cin >> inp;
        v.push_back(inp);
    }
    i64 mx = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> tem;
        for (int j = 0; j < v.size(); j++)
            if (j >= i)
                tem.push_back(v[j]);
        //        cout << "calculating for " << i << endl;
        mx = max(mx, f(tem));
    }
    cout << mx << endl;
}