#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
map<ll, bool> mp;
int main()
{
    scanf("%I64d", &n);
    while (n != 1)
    {
        if (mp.find(n) != mp.end())
        {
            printf("UNHAPPY\n");
            return 0;
        }
        mp[n] = 1;
        ll temp = 0;
        while (n)
        {
            int x = n % 10;
            temp += x * x;
            n /= 10;
        }
        n = temp;
    }
    printf("HAPPY\n");
}