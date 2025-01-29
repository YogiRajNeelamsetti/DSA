class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        map<int, int> mpp;
        for(int ele : nums) {
            mpp[ele]++;
            if(mpp[ele] > 2) mpp[ele]--;
        }
        int j = 0;
        for(auto pair : mpp) {
            for(int i = 0; i < pair.second; i++) {
                nums[j++] = pair.first;
                k++;
            }
        }

        return k;
    }
};