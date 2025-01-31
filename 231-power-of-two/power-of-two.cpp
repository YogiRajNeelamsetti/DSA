class Solution {
public:
    bool isPowerOfTwo(int n) {
        unsigned int m = n;
        if(n <= 0) return false;
        if((m & (m - 1)) == 0) return true;;
        return false;
    }
};