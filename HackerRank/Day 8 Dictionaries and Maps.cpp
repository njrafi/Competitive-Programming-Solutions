#include <bits/stdc++.h>
using namespace std;


int main() {
    string s1,s2;
    int n;
    map<string,string> m;
    map<string,bool> m2;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s1 >> s2;
        m[s1] = s2;
        m2[s1] = 1;
    }
    
    while(cin >> s1)   
    {
        if(m2[s1])
            cout << s1 << "=" << m[s1];
        else
            cout << "Not found";
        cout << endl;
    }
    return 0;
}
