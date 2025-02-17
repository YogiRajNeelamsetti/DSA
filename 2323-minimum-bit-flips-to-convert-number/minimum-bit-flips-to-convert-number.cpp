class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        goal = start ^ goal;
        while(goal) {
            cnt += (goal & 1);
            
            goal >>= 1;
        }

        return cnt;
    }
};