#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mat1[55] = {0}, mat2[55] = {0};
    int cnt = 0, n, a, b;
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        cin >> a >> b;
        if (!mat1[a] && !mat2[b])
        {
            cnt += 2;
            mat1[a]++;
            mat2[b]++;
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
