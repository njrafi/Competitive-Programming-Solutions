#include <bits/stdc++.h>

using namespace std;


#define mxn 100005

int zero[mxn] , one[mxn] , diff[mxn] , di[mxn];
map <int , vector<int> > m;
int main()
{
        int n;
        string s;
        scanf("%d", &n);
        cin >> s;

        m[0].push_back(0);
        di[0] = 0;


        for(int i = 0 ; i < s.size() ; i++)
        {


                if(s[i]=='0')
                {
                        zero[i+1] = zero[i] + 1;
                        one[i+1] = one[i];
                }
                else
                {
                        zero[i+1] = zero[i];
                        one[i+1] = one[i] + 1;
                }

                int diff = one[i+1] - zero[i+1];

                di[i+1] = diff;
//                cout << i + 1 << " " << diff << endl;
                m[diff].push_back(i+1);
        }


        int mx = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {

                int diff = di[i];
                int last = m[diff].back();
                mx = max(mx,last - i);
//                cout << last - i << endl;
//                cout << di[i] << " ";
        }


        cout << mx << endl;
}