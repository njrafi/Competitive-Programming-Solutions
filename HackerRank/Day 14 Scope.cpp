	int mn=10000,mx=0;
    Difference(vector<int> v)
    {
        for(int i=0;i<v.size();i++)
            {
            mx = max(mx,v[i]);
            mn = min(mn,v[i]);
        }
        maximumDifference = mx - mn;
        
    }
    void computeDifference()
        {}
    