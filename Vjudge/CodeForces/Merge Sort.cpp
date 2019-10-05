#include <bits/stdc++.h>


using namespace std;

#define mxn 100005

int tree[4 * mxn];
int vis = 1;
int k;
int ans[mxn];



vector< pair < int , int > > v;

void build(int n,int st,int en)
{
//        vis++;
//        cout << vis << " " << st << " " << en << endl;
        v.push_back(make_pair(st,en));

        if(st==en)
                return;


        int mid = (st+en-1)/2 , lc = 2 * n ,rc = lc + 1;


        if(vis<k)
        {
                vis += 2;
                v.pop_back();
                build(rc,mid+1,en);
                build(lc,st,mid);
        }

}


int main()
{
        int n ;
        scanf("%d %d", &n, &k);



        build(1,1,n);

        if(vis!=k)
        {
                cout << -1 << endl;
                return 0;
        }


//        for(int i = 0 ; i<v.size() ; i++)
//                cout << v[i].first << " " << v[i].second << endl;

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        vector<int> p;

        for(int i = 1; i <=n ; i++)
                p.push_back(i);

        reverse(p.begin(),p.end());
//        cout << endl;
        for(int i = 0 ; i<v.size() ; i++)
        {

                int l = v[i].first;
                int r = v[i].second;
                int szz = r - l + 1;
                vector<int> tem;


                while(szz--)
                {
                        tem.push_back(p.back());
                        p.pop_back();
                }

                sort(tem.begin(),tem.end());

//                cout << "debug" << endl;
//
//
//                cout << l << " " << r << endl;
//
//                for(int i = 0 ; i < tem.size() ; i++)
//                        cout << tem[i] << " ";
//                cout << endl;

                for(int i = l , j = 0; i <= r ; i++,j++)
                {

//                        cout << i << " " << l-i << endl;
                        ans[i] = tem[j];
                }
//                cout << v[i].first << " " << v[i].second << endl;
        }


        for(int i = 1 ; i <=n ; i++)
        {


                cout << ans[i];
                if(i==n)
                        cout << endl;
                else
                        cout << " ";
        }





}