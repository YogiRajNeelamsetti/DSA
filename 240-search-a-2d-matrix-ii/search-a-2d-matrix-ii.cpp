class Solution {
    bool bs(vector<int> &arr, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == target) return true;
            else if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            if(matrix[i][m - 1] >= target && target >= matrix[i][0]) {
                if(bs(matrix[i], 0, m - 1, target)) return true;
            }
        }

        return false;
    }
};