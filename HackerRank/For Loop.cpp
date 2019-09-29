#include <iostream>
#include <cstdio>
using namespace std;

void func(int num)
    {
    if(num==1)
        cout << "one";
    else if (num==2)
        cout << "two";
    else if (num==3)
        cout << "three";
        else if (num==4)
        cout << "four";
        else if (num==5)
        cout << "five";
        else if (num==6)
        cout << "six";
        else if (num==7)
        cout << "seven";
        else if (num==8)
        cout << "eight";
        else if (num==9)
        cout << "nine";
        else if(num%2)
            cout << "odd";
        else
            cout << "even";
        cout << endl;
        
}

int main() {
    int a,b;
        cin >> a >> b;
    for(int i=a;i<=b;i++)
        func(i);
    return 0;
}
