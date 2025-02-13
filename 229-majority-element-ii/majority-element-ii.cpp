class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> majority;
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for(auto pair : mpp) {
            if(pair.second > (n /3)) {
                majority.push_back(pair.first);
            }
        }

        return majority;
    }
};