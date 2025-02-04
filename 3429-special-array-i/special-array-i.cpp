class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;

        vector<int> parity(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                parity[i] = 0;
            } else {
                parity[i] = 1;
            }
        }

        for(int i = 1; i < parity.size(); i++) {
            if(parity[i] == parity[i - 1]) return false;
        }
        
        return true;
    }
};