class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        double res = log(n) / log(4);

        return abs(res - round(res)) < 1e-10;
    }
};