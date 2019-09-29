

//Write your code here
class Calculator {
public:
    int power(int n,int p)
    {
        if( n < 0 || p < 0) 
        {
            throw runtime_error("n and p should be non-negative");
        }
        int ans = 1;
        for(int i = 0 ; i < p ; i++)
            ans *= n;
        return ans;
    }
};


