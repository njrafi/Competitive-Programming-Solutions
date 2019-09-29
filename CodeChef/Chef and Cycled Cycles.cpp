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

inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}

//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}

//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}


#define mxn 100005

struct chain
{
        vi cum;
        int up,down,tot;
};


vector<chain> v;
int e[mxn];
int vv[mxn];
int vvind[mxn];
int vtot;
int etot;


int get_dis(int chid,int l,int r)
{
        if(l>r)
                swap(l,r);

        vi gg = v[chid].cum;

        return min( v[chid].cum[r-1] - v[chid].cum[l-1] , v[chid].tot - v[chid].cum[r-1] + v[chid].cum[l-1]);
}

void pre(int n)
{
        mem(vv,0);
        vtot = 0;

        Fre(i,1,n+1)
        {
                vv[i] = get_dis(i,v[i].up,v[i].down);
                vvind[i] = vv[i];
                vtot += vv[i];
                vv[i] += vv[i-1];
        }
}



int f(int v1,int c1,int v2,int c2)
{
        int p1e = ( e[v2-1] - e[v1-1]);
        int p1v = ( vv[v2-1] - vv[v1]);

        int path1 = p1e + p1v + get_dis(v1,c1,v[v1].down) + get_dis(v2,c2,v[v2].up);
        int path2 = etot + vtot - p1e - p1v + get_dis(v1,c1,v[v1].up) + get_dis(v2,c2,v[v2].down) - vvind[v1] - vvind[v2];
        return min(path1,path2);
}


void query_ans(int q)
{

        int v1,c1,v2,c2;
        while(q--)
        {
                fastRead(&c1);
                fastRead(&v1);
                fastRead(&c2);
                fastRead(&v2);

                if(v1>v2)
                {
                        swap(v1,v2);
                        swap(c1,c2);
                }

                if(v1==v2)
                        fastWrite(get_dis(v1,c1,c2));
                else
                        fastWrite(f(v1,c1,v2,c2));
        }
}


int main()
{

        int t,n,q , k , inp , l, r;
        fastRead(&t);
        while(t--)
        {
                v.clr;
                chain tem2;
                v.pb(tem2);
                mem(e,0);
                etot = 0;


                fastRead(&n);
                fastRead(&q);


                Fre(i,1,n+1)
                {
                        chain tem;
                        (tem.cum).pb(0);
                        tem.tot = 0;

                        fastRead(&k);
                        while(k--)
                        {
                                fastRead(&inp);
                                (tem.cum).pb( (tem.cum).back() + inp);
                                tem.tot += inp;
                        }

                        v.pb(tem);
                }

                Fre(i,1,n)
                {
                        fastRead(&l);
                        fastRead(&r);
                        fastRead(&inp);
                        v[i].down = l;
                        v[i+1].up = r;
                        e[i] = inp;
                        e[i] += e[i-1];

                        etot += inp;
                }

                fastRead(&l);
                fastRead(&r);
                fastRead(&inp);
                v[n].down = l;
                v[1].up = r;
                e[n] = inp;
                e[n] += e[n-1];
                etot += inp;



                pre(n);
                query_ans(q);



        }

        return 0;
}

