class Solution {
public:

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;
        
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int mul = nums[i] * nums[j];

                if(freq.find(mul) != freq.end()) {
                    count += 8 * freq[mul];
                }

                freq[mul]++;
            }
        }

        return count;
    }
};