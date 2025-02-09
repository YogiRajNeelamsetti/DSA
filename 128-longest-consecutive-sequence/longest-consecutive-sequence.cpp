class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;

        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        for(auto it : s) {
            if(s.find(it - 1) == s.end()) {
                int cnt = 1;
                int x = it;
                while(s.find(x + 1) != s.end()) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};