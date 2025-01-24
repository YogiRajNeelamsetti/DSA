class Solution {
public:
    vector<int> evenOddBit(int n) {

        int evenCnt = 0, oddCnt = 0;

        int i = 0;
        while(n) {
            if(n & 1) {
                if(i % 2 == 0) {
                    evenCnt++;
                } else {
                    oddCnt++;
                }
            }
            n = n >> 1;
            i++;
        }

        return {evenCnt, oddCnt};
    }
};