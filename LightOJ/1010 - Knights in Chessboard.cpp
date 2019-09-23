#include <stdio.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
#define CASE(a) printf("Case %d: ", a)
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
int maxi(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int t, c = 1, n, m;
    fastRead(&t);
    while (t--)
    {
        fastRead(&n);
        fastRead(&m);
        CASE(c++);
        if (n == 1 || m == 1)
            fastWrite(maxi(m, n));
        else if (n == 2 || m == 2)
        {
            int tem = maxi(m, n);
            if (tem % 4 == 0)
                fastWrite(tem);
            else if (tem % 4 > 1)
                fastWrite(tem - tem % 4 + 4);
            else
                fastWrite(tem - tem % 4 + 2);
        }
        else
        {
            n *= m;
            if (n % 2)
                n++;
            fastWrite(n / 2);
        }
    }
    return 0;
}
