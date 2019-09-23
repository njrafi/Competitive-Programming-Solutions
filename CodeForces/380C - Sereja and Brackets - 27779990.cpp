#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
typedef long long ll;
string s;
ll seg_len[10000005];
ll seg_left[10000005];
ll seg_right[10000005];
ll min(ll a, ll b) { return a < b ? a : b; }
typedef struct
{
    ll left;
    ll right;
    ll length;
} scratch;
void make(int ss, int se, int si)
{
    if (ss == se)
    {
        seg_len[si] = 0;
        seg_left[si] = (s[ss] == '(') ? 1 : 0;
        seg_right[si] = (s[ss] == ')') ? 1 : 0; /*if(ss==17){puts("sup");}*/
        return;
    }
    // if((qs<=ss)&&(qe>=se)){return;}
    int mid = (ss + se) / 2;
    make(ss, mid, (2 * si) + 1);
    make(mid + 1, se, (2 * si) + 2);
    seg_left[si] = seg_left[(2 * si) + 1] + seg_left[(2 * si) + 2] - min(seg_left[(2 * si) + 1], seg_right[(2 * si) + 2]);
    seg_right[si] = seg_right[(2 * si) + 1] + seg_right[(2 * si) + 2] - min(seg_left[(2 * si) + 1], seg_right[(2 * si) + 2]);
    seg_len[si] = seg_len[(2 * si) + 1] + seg_len[(2 * si) + 2] + 2 * min(seg_left[(2 * si) + 1], seg_right[(2 * si) + 2]);
}
const scratch sup = {0, 0, 0};
scratch create(scratch sc1, scratch sc2)
{
    scratch sc3;
    sc3.left = sc1.left + sc2.left - min(sc1.left, sc2.right);
    sc3.right = sc1.right + sc2.right - min(sc1.left, sc2.right);
    sc3.length = sc1.length + sc2.length + 2 * min(sc1.left, sc2.right);
    return sc3;
}
scratch sct;
scratch get(int ss, int se, int si, int qs, int qe)
{
    if (qs > se || qe < ss)
    {
        sct.length = 0;
        sct.left = 0;
        sct.right = 0;
        return sct;
    }
    if ((qs <= ss) && (qe >= se))
    {
        sct.length = seg_len[si];
        sct.left = seg_left[si];
        sct.right = seg_right[si];
        return sct;
    }
    int mid = (ss + se) / 2;
    return create(get(ss, mid, (2 * si) + 1, qs, qe), get(mid + 1, se, (2 * si) + 2, qs, qe));
}
int main()
{
    memset(seg_len, 0, sizeof seg_len);
    memset(seg_left, 0, sizeof seg_left);
    memset(seg_right, 0, sizeof seg_right);
    cin >> s;
    int n = s.length();
    int m;
    cin >> m;
    make(0, n - 1, 0);
    while (m--)
    {
        int start, end;
        cin >> start;
        cin >> end;
        start = start - 1;
        end = end - 1;
        scratch res = get(0, n - 1, 0, start, end);
        printf("%lld\n", res.length);
    }
    return 0;
}