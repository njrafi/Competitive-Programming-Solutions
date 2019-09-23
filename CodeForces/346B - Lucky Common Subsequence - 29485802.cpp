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
#define vpi vector<pii>
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
#define inf INT_MAX / 2
#define infll LLONG_MAX / 3
#define For(i, n) for (int i = 0; i < n; i++)
#define Fre(i, a, b) for (int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a, b) memset(a, b, sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ", a)
//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};
//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}
//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}
//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}
//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}
//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}
//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}
// bit manipulations
//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
string s1, s2, s3;
int z[2000006];
string s;
void calc()
{
    mem(z, 0);
    int l = 0, r = 0;
    int len = s.sz;
    Fre(i, 1, len)
    {
        if (i > r)
        {
            l = r = i;
            while (r < len && s[r] == s[r - l])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            if (z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else
            {
                l = i;
                while (r < len && s[r] == s[r - l])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}
void zf()
{
    s = s3 + '$' + s3;
    //        cout << s << endl;
    calc();
    //        For(i,s.sz)
    //                cout << z[i] << " ";
    For(i, s3.sz)
    {
        z[i] = z[i + s3.sz + 1];
        //                cout << z[i] << " ";
    }
    //        cout << endl;
}
struct info
{
    int l, r, idx;
};
int dp[105][105][105];
info dir[105][105][105];
int f(int l, int r, int idx)
{
    //        cout << l << " " << r << " " << idx << endl;
    if (idx == s3.sz)
        return -inf;
    if (l == s1.sz || r == s2.sz)
        return 0;
    if (dp[l][r][idx] != -1)
        return dp[l][r][idx];
    int ans = 0;
    if (s1[l] == s2[r])
    {
        int mx = 0;
        For(i, idx + 1) if (z[i] + i >= idx && s1[l] == s3[idx - i])
            mx = max(mx, idx - i + 1);
        //                if(l==4 && r==4)
        //                {
        //
        //                        For(i,idx)
        //                        {
        //
        //                                cout << i << " " << z[i] + i << " " << idx << " " << s3[idx-i] << endl;
        //                                if(z[i]+i>=idx && s1[l]==s3[idx-i])
        //                                        mx = max(mx,idx - i + 1);
        //
        //                        }
        //                        dbg(idx);
        //                        dbg(mx);
        //                }
        dir[l][r][idx] = {l + 1, r + 1, mx};
        ans = 1 + f(l + 1, r + 1, mx);
    }
    int tem1 = f(l, r + 1, idx);
    int tem2 = f(l + 1, r, idx);
    if (tem1 >= ans)
    {
        ans = tem1;
        dir[l][r][idx] = {l, r + 1, idx};
    }
    if (tem2 >= ans)
    {
        ans = tem2;
        dir[l][r][idx] = {l + 1, r, idx};
    }
    return dp[l][r][idx] = ans;
}
string ans;
int lala;
void print(int l, int r, int idx)
{
    //        cout << l << " " << r << " " << idx << endl;
    lala++;
    if (l >= s1.sz || r >= s2.sz || idx == s3.sz)
        return;
    info gg = dir[l][r][idx];
    if (gg.l == l + 1 && gg.r == r + 1)
        ans += s1[l];
    print(gg.l, gg.r, gg.idx);
}
int main()
{
    cin >> s1 >> s2 >> s3;
    //        cout << s1.sz << " " << s2.sz << " " << s3.sz << endl;
    zf();
    mem(dp, -1);
    int szz = f(0, 0, 0);
    //        dbg(szz);
    if (!szz)
    {
        cout << 0 << endl;
        return 0;
    }
    print(0, 0, 0);
    cout << ans << endl;
    return 0;
}