#include <stdio.h>
#include <math.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
#define CASE(a) printf("Case %d: ", a)
#define sf(n) scanf("%d", &n)
#define i64 long long int
#define max_n 1000006
inline void fastRead(i64 *a)
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
int prime[max_n / 32 + 2];
int v[max_n], yo;
int check(int n, int pos)
{
    return (n & 1 << pos);
}
int setbit(int n, int pos)
{
    return n = n | (1 << pos);
}
void sieve(int n)
{
    int lim = sqrt(n) + 1, i, j;
    v[0] = 2;
    for (i = 3; i <= lim; i += 2)
        if (!check(prime[i >> 5], i & 31))
            for (j = i * i; j <= n; j += 2 * i)
                prime[j >> 5] = setbit(prime[j >> 5], j & 31);
    yo = 1;
    for (i = 3; i <= n; i += 2)
        if (!check(prime[i / 32], i % 32))
            v[yo++] = i;
}
int nod(i64 n)
{
    int ans = 1, i;
    if (n == 1)
        return 0;
    for (i = 0; v[i] < sqrt(n) + 2 && i < yo; i++)
        if (n % v[i] == 0)
        {
            int tem = 0;
            while (n % v[i] == 0)
            {
                n /= v[i];
                tem++;
            }
            ans *= tem + 1;
        }
    if (n > 1)
        ans *= 2;
    return ans - 1;
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    i64 t, n, c = 1;
    sieve(1000006);
    sf(t);
    while (t--)
    {
        fastRead(&n);
        CASE(c++);
        fastWrite(nod(n));
    }
    return 0;
}
