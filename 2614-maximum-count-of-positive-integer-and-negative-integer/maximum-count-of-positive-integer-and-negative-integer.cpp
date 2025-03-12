int binarySearch(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] >= target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        }
    }
    return low;
}


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int neg = binarySearch(nums, n, 0);
        int pos = n - binarySearch(nums, n, 1);

        return (pos > neg) ? pos : neg;
    }
};