class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        
        double res = log(n) / log(3);

        return abs(res - round(res)) < 1e-10;
    }
};