#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> m;
    priority_queue<int> q;
    vector<int> ans;
    int n, inp, top;
    cin >> n;
    n *= n;
    while (n--)
    {
        cin >> inp;
        q.push(inp);
        m[inp]++;
    }
    while (!q.empty())
    {
        top = q.top();
        q.pop();
        if (m[top] > 0)
        {
            for (int i = 0; i < ans.size(); i++)
                m[__gcd(top, ans[i])] -= 2;
            ans.push_back(top);
            m[top]--;
        }
    }
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
