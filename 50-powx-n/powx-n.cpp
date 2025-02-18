class Solution {
public:
    double myPow(double x, int n) {

        long long exp = n;

        if(n < 0) {
            x = 1 / x;
            exp = abs((long long)n);
        }

        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == -1) return (exp & 1) ? x : -x;

        double ans = 1;

        while(exp) {
            if(exp % 2) {
                ans = ans * x;
            }
            x = x * x;
            exp >>= 1;
        }

        return ans;
    }
};