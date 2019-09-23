#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int row1 = 1, row2 = n; row1 <= row2; row1++, row2--)
    {
        if (row1 != row2)
            for (int col1 = 1, col2 = m; col1 <= m; col1++, col2--)
            {
                printf("%d %d\n", row1, col1);
                printf("%d %d\n", row2, col2);
            }
        else
            for (int col1 = 1, col2 = m; col1 <= col2; col1++, col2--)
                if (col1 != col2)
                {
                    printf("%d %d\n", row1, col1);
                    printf("%d %d\n", row1, col2);
                }
                else
                {
                    printf("%d %d\n", row1, col2);
                }
    }
    return 0;
}
