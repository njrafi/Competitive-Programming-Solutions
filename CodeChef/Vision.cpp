
/*
Idea and Code from

http://paulbourke.net/geometry/circlesphere/index.html#linesphere

http://paulbourke.net/geometry/circlesphere/raysphere.c

*/



#include <bits/stdc++.h>

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

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(tem[n][r]!=-1)return tem[n][r];return tem[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}






struct point
{
	double x,y,z;
	point() {}
	point(double xx,double yy,double zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}

};


bool RaySphere(point p1,point p2,point sc,double r)
{

	double a,b,c;

	double bb4ac;

	point tem;

	tem.x = p2.x - p1.x;
	tem.y = p2.y - p1.y;
	tem.z = p2.z - p1.z;

	a = tem.x * tem.x + tem.y * tem.y + tem.z * tem.z;

	b = 2 * (tem.x * (p1.x - sc.x) + tem.y * (p1.y - sc.y) + tem.z * (p1.z - sc.z));

	c = sc.x * sc.x + sc.y * sc.y + sc.z * sc.z;

	c += p1.x * p1.x + p1.y * p1.y + p1.z * p1.z;

	c -= 2 * (sc.x * p1.x + sc.y * p1.y + sc.z * p1.z);

	c -= r * r;

	bb4ac = b * b - 4 * a * c;


	if (abs(a) < eps || bb4ac < 0)
		return 0;

	return 1;
}





int main()
{

	double px,py,pz,qx,qy,qz,dx,dy,dz,cx,cy,cz,r;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> px >> py >> pz ;
		cin >> qx >> qy >> qz;
		cin >> dx >> dy >> dz;
		cin >> cx >> cy >> cz >> r;




		double lo = 0, hi = 2000000009, ans;

		while(abs(hi-lo)>eps)
		{


			double tt  = (hi+lo)/2;
			double qxx = qx + dx * tt;
			double qyy = qy + dy * tt;
			double qzz = qz + dz * tt;
			if(!RaySphere(point(px,py,pz),point(qxx,qyy,qzz),point(cx,cy,cz),r))
			{
				ans = tt;
				hi = tt;
			}
			else
				lo = tt;
		}

		cout << fixed << setprecision(10) << ans << endl;
	}













	return 0;
}


