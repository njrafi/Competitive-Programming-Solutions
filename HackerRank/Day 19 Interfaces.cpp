
class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) {
        int ans = 0;
        for(long long int i = 1 ; i * i <= n ; i++)
            if( n % i == 0)
            {
                ans += n / i + i;
                if( i == n / i) ans -= i;
            }
        return ans;
    }
};

