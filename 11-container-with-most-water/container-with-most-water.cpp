class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxAmount = 0;
        int minHeight = INT_MAX;
        while(l < r) {
            minHeight = min(height[l], height[r]);
            maxAmount = max(maxAmount, minHeight * (r - l));
            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxAmount;
    }
};