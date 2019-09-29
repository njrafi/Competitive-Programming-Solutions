#include <iostream>
using namespace std;
 
int main()
{
    int n,x,tp[10]={0},high=-1,in=-1,i;
    cin >> n;
    while (n--)
    {
        cin >> x;
        tp[x]++;
    }
    for (i=5;i>0;i--)
        {
            if (tp[i]>=high)
            {
                high=tp[i];
                in=i;
            }
        }
    cout << in <<endl;
}