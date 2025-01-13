class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        int majorityEle = 0;

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for(auto pair : mpp) {
            if(pair.second > n / 2) return pair.first;
        }

        return 0;
    }
};