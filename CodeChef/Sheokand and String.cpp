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
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX/2
#define infll LLONG_MAX/3
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)

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


#define mxn 1000006

struct node
{
        int nxt[28];
        int mn;
        int mnEnd;

        node()
        {
                mem(nxt,0);
                mn = inf;
                mnEnd = inf;
        }

}trie[mxn];

/// remember to initialize to 1
int nodenum;

void ins(string s,int stidx)
{
        int now = 0;
        For(i,s.sz)
        {

                int nxtNode = s[i] - 'a';

                if(!trie[now].nxt[nxtNode])
                {
                        trie[nodenum] = node();

                        trie[now].nxt[nxtNode] = nodenum++;

                }

                now = trie[now].nxt[nxtNode];
                trie[now].mn = min(trie[now].mn,stidx);
        }

        trie[now].mnEnd = min(trie[now].mnEnd,stidx);

}


int mxLen(string s,int lim)
{
        int now = 0;
        For(i,s.sz)
        {
                int nxtNode = s[i] - 'a';

                if(!trie[now].nxt[nxtNode])
                        return i;

                now = trie[now].nxt[nxtNode];

                if(trie[now].mn>lim)
                        return i;
        }


        return s.sz;
}


void get_ans(string s,int mx,int lim)
{
        int now = 0;

        string ans;
        For(i,mx)
        {
                ans += s[i];
                int nxtNode = s[i] - 'a';
                now = trie[now].nxt[nxtNode];

        }


        while(trie[now].mnEnd>lim)
        {
                For(i,26)
                        if(trie[now].nxt[i])
                        {
                                int gg = trie[now].nxt[i];
                                if(trie[gg].mn<=lim)
                                {
                                        ans += (i + 'a');
                                        now = gg;
                                        break;
                                }
                        }
        }

        cout << ans << endl;




}

int main()
{

        nodenum = 1;


        int n,q,lim;
        string s;
        sf(n);
        Fre(i,1,n+1)
        {
                cin >> s;
                ins(s,i);
        }


//        Fre(i,1,8)
//        {
//                cout << i << " = ";
//                cout << trie[i].mn << " " << trie[i].mnEnd << endl;
//        }

        sf(q);
        while(q--)
        {
                sf(lim);
                cin >> s;
//                cout << mxLen(s,lim) << endl;
                get_ans(s,mxLen(s,lim),lim);
        }








        return 0;
}


