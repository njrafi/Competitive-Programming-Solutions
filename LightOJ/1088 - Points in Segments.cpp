#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
inline void fastRead(int *a)
{
    register char c = 0;
    while (c < 33)
        c = gc();
    *a = 0;
    while (c > 33)
    {
        *a = *a * 10 + c - '0';
        c = gc();
    }
}
inline void fastWrite(int a)
{
    char snum[20];
    int i = 0;
    do
    {
        snum[i++] = a % 10 + 48;
        a = a / 10;
    } while (a != 0);
    i = i - 1;
    while (i >= 0)
        pc(snum[i--]);
    pc('\n');
}
int lower(int key, vector<int> &v)
{
    int low = 0, high = v.size() - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == key)
            high = mid - 1;
        else if (v[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int higher(int key, vector<int> &v)
{
    int low = 0, high = v.size() - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == key)
            low = mid + 1;
        else if (v[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    int t, l, r, n, q, tem, low, high;
    vector<int> v;
    fastRead(&t);
    for (int i = 1; i <= t; i++)
    {
        v.clear();
        fastRead(&n);
        fastRead(&q);
        while (n--)
        {
            fastRead(&tem);
            v.push_back(tem);
        }
        cout << "Case " << i << ":" << endl;
        while (q--)
        {
            fastRead(&l);
            fastRead(&r);
            low = lower(l, v);
            high = higher(r, v);
            fastWrite(high - low);
        }
    }
    return 0;
}
