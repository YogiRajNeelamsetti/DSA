class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posIdx = 0, negIdx = 1;
        vector<int> res(nums.size());

        for(auto num : nums) {
            if(num > 0) {
                res[posIdx] = num;
                posIdx += 2;
            }
            else {
                res[negIdx] = num;
                negIdx += 2;
            }
        }

        return res;
    }
};