#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[602];

int f(int n)
{

    int numberOfSwaps = 0;
    for (int i = 0; i < n; i++)
    {
        // Track number of elements swapped during a single array traversal


        for (int j = 0; j < n - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0)
        {
            break;
        }
    }

    return numberOfSwaps;
}




int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    printf("Array is sorted in %d swaps.\n",f(n));
    printf("First Element: %d\n",a[0]);
    printf("Last Element: %d\n", a[n-1]);

}
