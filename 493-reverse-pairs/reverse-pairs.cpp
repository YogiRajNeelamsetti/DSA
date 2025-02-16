class Solution {
    void merge(vector<int> &arr, int low, int mid, int high) {
        int p1 = low, p2 = mid + 1, k = 0;

        vector<int> temp(high - low + 1);

        while(p1 <= mid && p2 <= high) {
            if(arr[p1] <= arr[p2]) {
                temp[k++] = arr[p1++];
            } else {
                temp[k++] = arr[p2++];
            }
        }

        while(p1 <= mid) {
            temp[k++] = arr[p1++];
        }

        while(p2 <= high) {
            temp[k++] = arr[p2++];
        }

        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;
        for(int i = low; i <= mid; i++) {
            while(right <= high && (long long)arr[i] > (2LL * arr[right])) {
                right++;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        int mid = (low + high) / 2;
        if(low >= high) return cnt;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);

        merge(arr, low, mid, high);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};