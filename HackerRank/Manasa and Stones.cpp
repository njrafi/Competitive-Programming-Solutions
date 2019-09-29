#include <iostream>

using namespace std;


int main()

{
        int t,n,a,b,min,max,i;
        cin >> t;
        while(t--)
        {
                cin >> n >> a >> b;
                n--;
                if(a==b)
                {
                        cout << n*a << endl;
                        continue;
                }
                else if(a>b)
                {
                        min = b;
                        max = a;
                }
                else
                {
                        min = a;
                        max = b;
                }
                for(i=0;i<=n;i++)
                        cout << (n-i)*min + i* max << " ";
               cout << endl;

        }
        return 0;
}
