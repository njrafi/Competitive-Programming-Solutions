#include <bits/stdc++.h>
using namespace std;
int penalty[202][20];
int acnt[202];
int penal[202];
int n, m, cur, p, tim;
char ch, str[202], ver[10];
int last = 1, lasttim = 0, lead = 0;
string seq;
map<string, int> mp;
/*
2 2 2
AA
BB
AA A 1 NO
BB B 10 NO
  3 6 3
AA
BB
CC
BB  A 10 NO
CC A 20 NO
CC B 30 NO
BB A 40 NO
BB A 60 OK
AA A 70 OK
 */
int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        seq = str;
        mp[seq] = ++cur;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s %c %d %s", str, &ch, &tim, ver);
        int team = mp[str];
        int prb = ch - 'A';
        if (ver[0] == 'O')
        {
            acnt[team]++;
            penal[team] += tim + penalty[team][prb];
            if (last)
            {
                lead += tim - lasttim;
            }
            lasttim = tim;
            bool f = true;
            for (int i = 2; i <= n; i++)
            {
                if (acnt[1] < acnt[i] || (acnt[1] == acnt[i] && penal[1] > penal[i]))
                {
                    f = false;
                    break;
                }
            }
            last = f;
        }
        else
        {
            penalty[team][prb] += 20;
        }
    }
    if (last)
        lead += 300 - lasttim;
    cout << lead << endl;
}