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
#define READ freopen("input.txt", "r", stdin)
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
    int t, n, m, inp;
    cin >> t;
    string s;
    For(i, t)
    {
        printf("Case %d:\n", i + 1);
        cin >> n >> m;
        deque<int> d;
        while (m--)
        {
            cin >> s;
            if (s == "pushLeft")
                if (d.sz != n)
                {
                    cin >> inp;
                    cout << "Pushed in left: " << inp << endl;
                    d.push_front(inp);
                }
                else
                {
                    cin >> inp;
                    cout << "The queue is full" << endl;
                }
            else if (s == "pushRight")
                if (d.sz != n)
                {
                    cin >> inp;
                    cout << "Pushed in right: " << inp << endl;
                    d.push_back(inp);
                }
                else
                {
                    cin >> inp;
                    cout << "The queue is full" << endl;
                }
            else if (s == "popRight")
                if (d.sz != 0)
                {
                    cout << "Popped from right: " << d.back() << endl;
                    d.pop_back();
                }
                else
                    cout << "The queue is empty" << endl;
            else if (d.sz != 0)
            {
                cout << "Popped from left: " << d.front() << endl;
                d.pop_front();
            }
            else
                cout << "The queue is empty" << endl;
        }
    }
    return 0;
}
