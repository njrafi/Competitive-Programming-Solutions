#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define i64 long long
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mod 1000000007
#define For(i,n) for(int i=0;i<n;i++)
#define eps 1/120
#define ff first
#define ss second
#define clr(a) memset(a,-1,sizeof(a))




void func(int i,int j)
{
        if(i<10)
                cout << 0;
        cout << i << ":";
        if(j<10)
                cout << 0;
        cout << j  << endl;
}




int main()
{

        int hour,minute,t;
        double h_pos,m_pos,ang,inp;
        double calc[12][60];
        for(int i=0;i<12*60;i++)
        {
                hour = i/60;
                minute = i%60;
                h_pos = (double)i/2;
                m_pos = minute*6;
                if( max(h_pos,m_pos) - min(h_pos,m_pos) <=180)
                                ang = max(h_pos,m_pos) - min(h_pos,m_pos);
                else
                        ang = 360 - max(h_pos,m_pos) + min(h_pos,m_pos);
                calc[hour][minute] = ang*10000;
               // cout << hour << ':' << minute << "  " << h_pos << " " << m_pos<< " " << ang <<endl;
        }

        cin >> t;
        while(t--)
        {
                cin >> inp;
                inp *= 10000;
                for(int i=0;i<12;i++)
                        for(int j=0;j<60;j++)
                                if( max(calc[i][j],inp)-min(calc[i][j],inp) < 83.333333 )
                                        func(i,j);

        }
        return 0;
}

