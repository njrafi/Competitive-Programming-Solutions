#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */       int n;
    int ans = 0;
    cin >> n;
    getchar();
    while(n--)
    {
        string s;
        getline(cin,s);
       // cout << s << endl;
        for(int i = 0 ; i< s.size() ; i++)
            s[i] = tolower(s[i]);

        if (s.find("hackerrank") != -1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
