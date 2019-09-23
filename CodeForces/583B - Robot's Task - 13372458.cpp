#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, dir = 0, info = 0, inp;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        cin >> inp;
        v.push_back(inp);
    }
    while (1)
    {
        for (int i = 0; i < v.size(); i++)
            if (v[i] <= info && v[i] != -1)
            {
                v[i] = -1;
                info++;
            }
        if (info == v.size())
            break;
        dir++;
        for (int i = v.size() - 1; i >= 0; i--)
            if (v[i] <= info && v[i] != -1)
            {
                v[i] = -1;
                info++;
            }
        if (info == v.size())
            break;
        dir++;
    }
    cout << dir << endl;
    return 0;
}
