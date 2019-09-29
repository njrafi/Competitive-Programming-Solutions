#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n,ans=0;
    string s;
    cin >> n;
    while(n)
        {
        if(n%2)
            s.push_back('1');
        else
            s.push_back('0');
        n /= 2;
    }
    int tem = 0;
    for(int i=0;i<s.size();i++)
        {
        if(s[i]=='1')
            tem++;
        else
            {
            ans = max(ans,tem);
            tem = 0;
        }
    }
    ans = max(ans,tem);
    cout << ans;
    return 0;
}
