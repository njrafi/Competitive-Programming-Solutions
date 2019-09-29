#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    while(n--)
    {
        string firstName,email;
        cin >> firstName >> email;
        string domain;
        bool last = 0;
        for(int i = 0 ; i < email.size() ; i++)
            if(last) domain += email[i];
            else if(email[i] == '@') last = 1;
        
        if(domain == "gmail.com") ans.push_back(firstName);
        
    }

    sort(ans.begin(),ans.end());
    for(auto i: ans) cout << i << endl;
}
