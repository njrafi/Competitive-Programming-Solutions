#include <bits/stdc++.h>
using namespace std;
int main()
{
    string inp;
    vector<int> v;
    cin >> inp;
    int i = 0;
    while (i < inp.size())
    {
        if (inp[i] == '.')
        {
            v.push_back(0);
            i++;
        }
        else
        {
            if (inp[i + 1] == '.')
                v.push_back(1);
            else
                v.push_back(2);
            i += 2;
        }
    }
    for (i = 0; i < v.size(); i++)
        cout << v[i];
    return 0;
}
