#include <bits/stdc++.h>

using namespace std;

class Solution {
    //Write your code here
public:
    queue<int> q;
    stack<int> s;
    void pushCharacter(int gg)
    {
        s.push(gg);
    }
    void enqueueCharacter(int gg) 
    {
        q.push(gg);
    }
    char popCharacter()
    {
        int tem = s.top();
        s.pop();
        return tem;
    }
    char dequeueCharacter()
    {
        int tem = q.front();
        q.pop();
        return tem;
    }
};