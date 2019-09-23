#include <bits/stdc++.h>
using namespace std;
int func(int n)
{
    vector<int> v;
    int tem = 0, res, i, one = 0, pos;
    while (n)
    {
        v.push_back(n % 2);
        n /= 2;
    }
    for (i = 0; i < v.size() - 1; i++)
    {
        if (v[i] == 1 && v[i + 1] == 0)
        {
            swap(v[i], v[i + 1]);
            tem++;
            pos = i + 1;
            break;
        }
    }
    if (!tem)
    {
        v[v.size() - 1] = 0;
        v.push_back(1);
        pos = v.size() - 1;
    }
    for (i = 0; i < pos; i++)
    {
        if (v[i] == 1)
            one++;
    }
    for (i = 0; i < pos; i++)
    {
        if (one)
        {
            v[i] = 1;
            one--;
        }
        else
            v[i] = 0;
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i])
            res += pow(2, i);
    return res;
}
int main()
{
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        printf("Case %d: %d\n", i, func(n));
    }
    return 0;
}
