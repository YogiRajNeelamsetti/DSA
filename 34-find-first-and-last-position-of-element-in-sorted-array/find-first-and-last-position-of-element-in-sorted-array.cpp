class Solution {

    int leftBS(vector<int> &nums, int low, int high, int target) {
        int p1 = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                p1 = mid;
                high = mid - 1;
            }
        }

        return p1;
    }

    int rightBS(vector<int> &nums, int low, int high, int target) {
        int p2 = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                p2 = mid;
                low = mid + 1;
            }
        }
        
        return p2;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int p1 = leftBS(nums, 0, n - 1, target);
        int p2 = rightBS(nums, 0, n - 1, target);

        return {p1, p2};
    }
};