#include <bits/stdc++.h>
using namespace std;
void update(int *a,int *b) {
    int tem;
    tem = *a + *b;
    *b = abs(*a-*b);
    *a = tem;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    cin >> a >> b;
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
