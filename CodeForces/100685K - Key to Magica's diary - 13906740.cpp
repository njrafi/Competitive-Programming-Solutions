#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif
using namespace std;
#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int, int>
#define pri priority_queue<int>
#define rev_pri priority_queue<int, vector<int>, greater<int>>
#define mpi map<int, int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
#define eps 1e-8
#define ff first
#define ss second
#define clr(a) memset(a, -1, sizeof(a))
#define rset(a) memset(a, 0, sizeof(a))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define READ freopen("in.txt", "r", stdin)
#define sz size()
#define dbg printf("yo\n")
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//functions
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(!n)return 1;i64 x=(bigmod(num,n/2)*bigmod(num,n/2))%mod;if(n%2)x=(x*num)%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2);}
int main()
{
    // READ;
    int n, j;
    string s, s1, s2;
    vs v, v2;
    map<string, int> m;
    scanf("%d\n", &n);
    while (n--)
    {
        getline(cin, s);
        For(i, s.sz)
        {
            if (!isalpha(s[i]))
                s[i] = ' ';
            else
                s[i] = tolower(s[i]);
        }
        stringstream ss;
        ss << s;
        while (ss >> s)
            v.pb(s);
    }
    cin >> n;
    while (n--)
    {
        cin >> s;
        m[s] = -1;
    }
    For(i, v.sz)
    {
        if (m[v[i]] == -1)
            continue;
        m[v[i]]++;
        v2.pb(v[i]);
    }
    For(i, v2.sz - 1)
    {
        s1 = v2[i] + " " + v2[i + 1];
        s2 = v2[i + 1] + " " + v2[i];
        if (s1 == s2)
            m[s1]++;
        else
        {
            m[s1]++;
            m[s2]++;
        }
        //cout << v[i] << " " << m[v[i]] << endl;
    }
    cin >> n;
    while (n--)
    {
        cin >> s1 >> s2;
        i64 c1 = 0, c2 = 0, c3 = 0;
        c1 = m[s1];
        c2 = m[s2];
        // cout << s << endl;
        c3 = m[s1 + " " + s2];
        if (c1 == -1 || c2 == -1 || !c3 || v2.sz == 1 || !c1 || !c2)
        {
            cout << 0.0000000000 << endl;
            continue;
        }
        double a1, a2, a3, ans;
        a1 = (double)c1 / v2.sz;
        a2 = (double)c2 / v2.sz;
        //cout << c1 << " " << c2 << " " << c3 << endl;
        a3 = (double)c3 / (v2.sz - 1);
        // cout << a1 << " " << a2 << " " << a3 << endl;
        ans = a3 / (a1 * a2);
        printf("%.15f\n", ans);
    }
    return 0;
}