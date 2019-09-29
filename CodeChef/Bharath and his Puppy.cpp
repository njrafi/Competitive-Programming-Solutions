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
#define inf 536870911
#define infll 12345678901234567
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
//i64 dp[60][60];


//functions

//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}

//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}

//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}

//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

//int popcount(i64 num){bitset<70> tem(num);return tem.count();}

//matrix rot(matrix a){matrix res;res.row = a.col;res.col = a.row;For(i,a.row)For(j,a.col)res.mat[j][a.row-i-1] = a.mat[i][j];return res;}


struct node
{
        i64 sum;
        pair<i64,i64> mx,mn;
};

vi v;
node tree[400005];

void build(int i,int s,int e)
{
        if(s==e)
        {
                tree[i].sum = v[s];
                tree[i].mx.ff = v[s];
                tree[i].mx.ss = -inf;
                tree[i].mn.ff = v[s];
                tree[i].mn.ss = inf;
                return ;
        }

        int mid = (s+e)/2;
        int lc = i*2;
        int rc = lc + 1;
        build(2*i,s,mid);
        build(2*i+1,mid+1,e);

        tree[i].sum = tree[lc].sum + tree[rc].sum;



        si tem;
        vi vv;

        tem.insert(tree[lc].mx.ff);
        tem.insert(tree[lc].mx.ss);
        tem.insert(tree[rc].mx.ff);
        tem.insert(tree[rc].mx.ss);
        foreach(i,tem)
                vv.pb(*i);
        reverse(all(vv));

        tree[i].mx.ff = vv[0];
        tree[i].mx.ss = vv[1];

        tem.clr;
        vv.clr;

        tem.insert(tree[lc].mn.ff);
        tem.insert(tree[lc].mn.ss);
        tem.insert(tree[rc].mn.ff);
        tem.insert(tree[rc].mn.ss);
        foreach(i,tem)
                vv.pb(*i);

        tree[i].mn.ff = vv[0];
        tree[i].mn.ss = vv[1];



}

i64 sum(int i,int s,int e,int l ,int r)
{
        if(r<s || e<l)
                return 0;
        if(l<=s && e<=r)
                return tree[i].sum;
        int mid = (s+e)/2;
        i64 p1 = sum(2*i,s,mid,l,r);
        i64 p2 = sum(2*i+1,mid+1,e,l,r);
        return (p1+p2);
}


pair<i64,i64> smax(int i,int s,int e,int l ,int r)
{
        if(r<s || e<l)
                return mp(-inf,-inf);
        if(l<=s && e<=r)
                return tree[i].mx;
        int mid = (s+e)/2;
        pii p1 = smax(2*i,s,mid,l,r);
        pii p2 = smax(2*i+1,mid+1,e,l,r);

        si tem;
        tem.insert(p1.ff);
        tem.insert(p1.ss);
        tem.insert(p2.ff);
        tem.insert(p2.ss);

        vi vv;

        foreach(i,tem)
                vv.pb(*i);
        reverse(all(vv));

        return mp(vv[0],vv[1]);
}



pair<i64,i64> smin(int i,int s,int e,int l ,int r)
{
        if(r<s || e<l)
                return mp(inf,inf);
        if(l<=s && e<=r)
                return tree[i].mn;
        int mid = (s+e)/2;
        pii p1 = smin(2*i,s,mid,l,r);
        pii p2 = smin(2*i+1,mid+1,e,l,r);

        si tem;
        tem.insert(p1.ff);
        tem.insert(p1.ss);
        tem.insert(p2.ff);
        tem.insert(p2.ss);

        vi vv;

        foreach(i,tem)
                vv.pb(*i);

        return mp(vv[0],vv[1]);
}

void update(int i,int s,int e,int idx,int val)
{
        if(s==e)
        {
                tree[i].sum = val;
                tree[i].mx.ff = val;
                tree[i].mn.ff = val;
                return;
        }
        int mid = (s+e)/2;
        int lc = 2 * i;
        int rc = lc + 1;
        if(idx<=mid)
                update(2*i,s,mid,idx,val);
        else
                update(i*2+1,mid+1,e,idx,val);

        tree[i].sum = tree[lc].sum + tree[rc].sum;



        si tem;
        vi vv;

        tem.insert(tree[lc].mx.ff);
        tem.insert(tree[lc].mx.ss);
        tem.insert(tree[rc].mx.ff);
        tem.insert(tree[rc].mx.ss);
        foreach(i,tem)
                vv.pb(*i);
        reverse(all(vv));

        tree[i].mx.ff = vv[0];
        tree[i].mx.ss = vv[1];

        tem.clr;
        vv.clr;

        tem.insert(tree[lc].mn.ff);
        tem.insert(tree[lc].mn.ss);
        tem.insert(tree[rc].mn.ff);
        tem.insert(tree[rc].mn.ss);
        foreach(i,tem)
                vv.pb(*i);

        tree[i].mn.ff = vv[0];
        tree[i].mn.ss = vv[1];

}

int main()
{

        //ios_base::sync_with_stdio(false);cin.tie(0);
        int n,inp,l,r,q;
        v.pb(0);
        string s;

        sf(n);

        For(i,n)
        {
                sf(inp);
                v.pb(inp);
        }

        build(1,1,n);
        sf(q);

        while(q--)
        {
                cin >> s >> l >> r;

                if(s!="U")
                {
                        if(l>r || l<1 || r>n)
                        {
                                cout << "!!!" << endl;
                                continue;
                        }
                }
                else
                {
                        if(l<1 || l>n)
                        {
                                cout << "!!!" << endl;
                                continue;
                        }
                }

                if(s=="A")
                        cout << sum(1,1,n,l,r) << endl;
                else if(s=="U")
                        update(1,1,n,l,r);
                else if(s=="M")
                        cout << smax(1,1,n,l,r).ff << endl;
                else if(s=="m")
                        cout << smin(1,1,n,l,r).ff << endl;
                else if(s=="S")
                {
                        i64 ans =  smax(1,1,n,l,r).ss;
                        if(ans==-inf)
                                cout << "NA" ;
                        else
                                cout << ans ;
                        cout << endl;
                }
                else
                {

                        i64 ans =  smin(1,1,v.sz,l,r).ss ;
                        if(ans==inf)
                                cout << "NA";
                        else
                                cout << ans;
                        cout << endl;
                }
        }






        return 0;
}

