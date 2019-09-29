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
    int n,inp;
    cin >> n;
    vector<int> v;
    while(n--)   
    {
        cin >> inp;
        v.push_back(inp);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    return 0;
}
