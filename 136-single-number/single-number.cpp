class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for(auto pair : mpp) {
            if(pair.second == 1) {
                return pair.first;
            }
        }

        return 0;
    }
};