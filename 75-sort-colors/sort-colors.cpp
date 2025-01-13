class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int j = 0;
        for(auto pair : mpp) {
            for(int i = 0; i < pair.second; i++) {
                nums[j] = pair.first;
                j++;
            }
        }
    }
};