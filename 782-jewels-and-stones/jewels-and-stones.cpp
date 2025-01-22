class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.size();

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(jewels.find(stones[i]) != string::npos) {
                count++;
            }
        }

        return count;
    }
};