#include <bits/stdc++.h>
using namespace std;
/*
         Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d%d", &a, &b)
#define sfff(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define f0(i, b) for (int i = 0; i < (b); i++)
#define f1(i, b) for (int i = 1; i <= (b); i++)
#define f2(i, a, b) for (int i = (a); i <= (b); i++)
#define fr(i, b, a) for (int i = (b); i >= (a); i--)
#define CIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define N 100005
#define TEST_CASE(t) for (int z = 1; z <= t; z++)
#define PRINT_CASE printf("Case %d: ", z)
#define NOT_VISITED 0
#define IS_VISITED 1
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9 + 7;
const int maxn = (int)2e5 + 5;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
int n, m, u, v, w;
vector<plli> nodes[N];
vector<int> path;
int par[N];
ll d[N];
void initGraph()
{
    for (int i = 0; i < n + 10; i++)
    {
        par[i] = -1;
        d[i] = LLONG_MAX;
    }
}
void dijkstra()
{
    priority_queue<plli, vector<plli>, greater<plli>> Q;
    Q.push({d[1] = 0, 1});
    par[1] = -1;
    while (!Q.empty())
    {
        int u = Q.top().ss;
        Q.pop();
        for (auto e : nodes[u])
        {
            int v = e.ss;
            int cost = e.ff;
            ll total = d[u] + cost;
            if (total < d[v])
            {
                //d[v]=total;
                par[v] = u;
                Q.push({(d[v] = total), v});
            }
        }
    }
}
int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cin>>n>>m;
    sff(n, m);
    for (int i = 1; i <= m; i++)
    {
        //cin>>u>>v>>w;
        scanf("%d%d%d", &u, &v, &w);
        nodes[u].pb({w, v});
        nodes[v].pb({w, u});
    }
    initGraph();
    dijkstra();
    //    for(int i=1 ; i<=n ; i++)
    //    {
    //        cout << i << " " << d[i] <<endl;
    //    }
    int u = n;
    path.pb(u);
    if (par[n] == -1)
    {
        printf("-1\n");
        return 0;
    }
    while (par[u] != -1)
    {
        path.pb(par[u]);
        u = par[u];
    }
    //cout<<path[path.size()-1];
    printf("%d", path[path.size() - 1]);
    for (int i = path.size() - 2; i >= 0; i--)
    {
        //cout<<" "<<path[i];
        printf(" %d", path[i]);
    }
    //cout<<endl;
    printf("\n");
    path.clear();
    return 0;
}