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


//int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}

inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}
inline void fastWrite2(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc(' ');}

//int bigmod(int num,int n){if(n==0)return 1;int x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

//int modinverse(int num){return bigmod(num,mod-2)%mod;}

//int po(int a,int b){int ans=1;while(b--)ans *= a;return ans;}

//int ncr(int n,int r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

bool checkbit(int mask,int bit){return mask & (1<<bit);}

int setbit(int mask,int bit){ return mask  | (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}

#define mxn 300005

mpi who;
int trie[mxn * 31][3];
int node;
int start[mxn];


void ins(int tree_node,int par_node,int num)
{
        int now = node++;
        start[tree_node] = now;
        int par_now = par_node;
        bool par_go = 1;


        // Iterate through the parent trie till same path of num exist (until par_go = 1)
        // when iterating if there is a opposite bit children make it the children of our current nodes

        for(int i = 31 ; i >= 0 ; i--)
        {
                bool nxt = checkbit(num,i);

                if(par_go)
                {
                        if(trie[par_now][1-nxt])
                                trie[now][1-nxt] = trie[par_now][1-nxt];

                        if(trie[par_now][nxt])
                                par_now = trie[par_now][nxt];
                        else
                                par_go = 0;
                }


                trie[now][nxt] = node++;

                now = trie[now][nxt];
        }
}


pair<int,int> query(int nd,int k)
{

        int ans = 0 , ans2 = 0;
        int now = start[nd];
        int now2 = start[nd];

        for(int i = 31 ; i>= 0 ; i--)
        {
                bool nxt = checkbit(k,i);

                if(trie[now][nxt])
                        now = trie[now][nxt];
                else
                {
                        now = trie[now][nxt^1];
                        ans = setbit(ans,i);
                }

                nxt ^= 1;

                if(trie[now2][nxt])
                {
                        ans2 = setbit(ans2,i);
                        now2 = trie[now2][nxt];
                }
                else
                        now2 = trie[now2][nxt^1];
        }

        return mp(ans,ans2);
}

int main()
{
        int n,q,u,v,k,t,r;

        int now = 1;
        node = 1;



        fastRead(&n);
        fastRead(&q);
        fastRead(&r);
        fastRead(&u);

        who[r] = now++;
        ins(who[r],0,u);


        For(i,n-1)
        {
                fastRead(&u);
                fastRead(&v);
                fastRead(&k);
                who[u] = now++;

                ins(who[u],start[who[v]],k);
        }

        int last_answer = 0;

        while(q--)
        {
            fastRead(&t);

            t ^= last_answer;

            if (!t)
            {
                fastRead(&v);
                fastRead(&u);
                fastRead(&k);

                u ^= last_answer;
                v ^= last_answer;
                k ^= last_answer;

                who[u] = now++;

                ins(who[u],start[who[v]],k);

            }
            else
            {
                fastRead(&v);
                fastRead(&k);

                v ^= last_answer;
                k ^= last_answer;
                v = who[v];

                pair<int,int> ans = query(v,k);

                int min_answer = ans.ff;
                int max_answer = ans.ss;

                fastWrite2(min_answer);
                fastWrite(max_answer);


                last_answer = min_answer ^ max_answer;
            }
        }














        return 0;
}


