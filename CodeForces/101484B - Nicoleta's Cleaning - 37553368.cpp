#include <bits/stdc++.h>
#define LIM 100005
#define vi vector<int>
#define pb push_back
#define OPEN 0
#define CLOSE 1
#define segVar int lft = 2 * node, rgt = 2 * node + 1, md = (st + ed) / 2
using namespace std;
struct point
{
    int x, y, z, ans;
    point() {}
    point(int xx, int yy, int zz, int aa = 0)
    {
        x = xx;
        y = yy;
        z = zz;
        ans = aa;
    }
};
struct rect
{
    int ax, ay, bx, by, z;
    rect() {}
    rect(int xx, int yy, int xxx, int yyy, int zz)
    {
        ax = xx;
        ay = yy;
        bx = xxx;
        by = yyy;
        z = zz;
    }
};
struct info
{
    int x, y;
    info() {}
    info(int xx, int yy = 0)
    {
        x = xx;
        y = yy;
    }
};
struct range
{
    int x, ymin, ymax, type;
};
bool cmppx(point a, point b)
{
    return a.x < b.x;
}
bool cmppz(point a, point b)
{
    return a.z < b.z;
}
bool cmprx(range a, range b)
{
    return (a.x == b.x && a.type > b.type) || a.x < b.x;
}
int n, m, cx, cy;
int mxx = 0, mxy = 0;
point points[5 * LIM];
rect rects[5 * LIM];
range ranges[5 * LIM];
vi X, Y;
map<int, int> mpy;
int segTree[20 * LIM];
int query(int node, int st, int ed, int p, int carry = 0)
{
    segTree[node] += carry;
    if (ed < p || st > p)
        return 0;
    if (st >= p && ed <= p)
        return segTree[node];
    segVar;
    int x = segTree[node];
    segTree[node] = 0;
    int a = query(lft, st, md, p, x), b = query(rgt, md + 1, ed, p, x);
    if (p <= md)
        return a;
    else
        return b;
}
void update(int node, int st, int ed, int l, int r, int v, int carry = 0)
{
    segTree[node] += carry;
    if (ed < l || st > r)
        return;
    if (st >= l && ed <= r)
    {
        segTree[node] += v;
        return;
    }
    segVar;
    update(lft, st, md, l, r, v, segTree[node]);
    update(rgt, md + 1, ed, l, r, v, segTree[node]);
    segTree[node] = 0;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].z = i;
        X.pb(points[i].x);
        Y.pb(points[i].y);
    }
    for (int i = 0; i < 2 * m; i += 2)
    {
        int ax, ay, bx, by;
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        ranges[i].x = ax;
        ranges[i].ymin = ay;
        ranges[i].ymax = by;
        ranges[i].type = OPEN;
        ranges[i + 1].x = bx;
        ranges[i + 1].ymin = ay;
        ranges[i + 1].ymax = by;
        ranges[i + 1].type = CLOSE;
        X.pb(ax);
        X.pb(bx);
        Y.pb(ay);
        Y.pb(by);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 0; i < Y.size(); i++)
    {
        if (!mpy[Y[i]])
        {
            mpy[Y[i]] = ++cy;
        }
    }
    for (int i = 0; i < n; i++)
        points[i].y = mpy[points[i].y];
    for (int i = 0; i < 2 * m; i++)
    {
        ranges[i].ymin = mpy[ranges[i].ymin];
        ranges[i].ymax = mpy[ranges[i].ymax];
    }
    for (int i = 0; i < n; i++)
    {
        mxx = max(mxx, points[i].x);
        mxy = max(mxy, points[i].y);
    }
    for (int i = 0; i < m; i++)
    {
        mxx = max(mxx, rects[i].bx);
        mxy = max(mxy, rects[i].by);
    }
    sort(points, points + n, cmppx);
    sort(ranges, ranges + 2 * m, cmprx);
    //
    //    cout << "POINTS " << endl;
    //    for(int i=0; i<n; i++) cout << points[i].x << ' ' << points[i].y << endl;
    //    cout << "RECTS: " << endl;
    //    for(int i=0; i<2*m; i++) cout << ranges[i].x << ' ' << ranges[i].ymin << ' ' << ranges[i].ymax << ' ' <<ranges[i].type << endl;
    //    update(1, 1,mxy, 1,2, 1);
    //    update(1, 1,mxy, 1,2, -1);
    //    update(1, 1,mxy, 2,3, 1);
    //    cout << query(1, 1,mxy, 2) << endl;
    int cmd = 0;
    int i = 0, j = 0;
    while (i < n && j < 2 * m)
    {
        //        cout << "STEP: " << cmd << " " << points[i].x << ' ' << ranges[j].x << endl; getchar();
        if (points[i].x < ranges[j].x || (points[i].x == ranges[j].x && ranges[j].type == OPEN))
        {
            points[i].ans = query(1, 1, mxy, points[i].y);
            i++;
            //            cout << "ONE: " << cmd++ << endl;
        }
        else if (points[i].x == ranges[j].x)
        {
            //            if(ranges[j].type == OPEN) {
            ////                update(1, 1,mxy, ranges[j].ymin, ranges[j].ymax, 1);
            ////                j++;
            ////                cout << "TWO: " << cmd++ << endl;
            //            }
            //            else {
            update(1, 1, mxy, ranges[j].ymin + 1, ranges[j].ymax - 1, -1);
            j++;
            //                cout << "THREE: " << cmd++ << endl;
            //            }
        }
        else
        {
            if (ranges[j].type == OPEN)
            {
                update(1, 1, mxy, ranges[j].ymin + 1, ranges[j].ymax - 1, 1);
                //                cout << "FOUR: " << cmd++ << endl;
            }
            else
            {
                update(1, 1, mxy, ranges[j].ymin + 1, ranges[j].ymax - 1, -1);
                //                cout << "FIVE: " << cmd++ << endl;
            }
            j++;
        }
        //        cout << i << ' ' << j << " xxx " << segTree[1] << endl;
    }
    while (i < n)
        points[i++].ans = 0;
    sort(points, points + n, cmppz);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", points[i].ans);
    }
}
/*
2 2
0 0
10 10
-1 -100 1 100
-100 -1 100 1
POINTS
0 3
10 5
RECTS:
-100 2 4 0
-1 1 6 0
1 1 6 1
100 2 4 1
2
2
 2 3
0 0
10 10
-10 -10 10 15
5 5 20 20
9 9 11 11
POINTS
0 2
10 5
RECTS:
-10 1 7 0
5 3 8 0
9 4 6 0
10 1 7 1
11 4 6 1
20 3 8 1
STEP: 0 0 -10
FOUR: 0
0 1 xxx 1
STEP: 1 0 5
 ONE: 1
1 1 xxx 0
STEP: 2 10 5
 FOUR: 2
1 2 xxx 0
STEP: 3 10 9
 FOUR: 3
1 3 xxx 0
STEP: 4 10 10
 THREE: 4
2 3 xxx 0
1
3
 */
