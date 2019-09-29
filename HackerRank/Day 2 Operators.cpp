#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double a,b,c;
    cin >> a >> b >> c;
    int ans = (int)round(a*(1+b/100+c/100));
    printf("The total meal cost is %d dollars.",ans);
    return 0;
}
