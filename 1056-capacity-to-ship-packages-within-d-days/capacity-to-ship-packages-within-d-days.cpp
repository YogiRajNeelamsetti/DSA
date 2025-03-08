class Solution {
    int daysReq(vector<int>& weights, int capacity) {
        int days = 1, load = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum = 0, maxEl = INT_MIN;

        for(int &ele : weights) {
            sum += ele;
            if(ele > maxEl) maxEl = ele;
        }
        int low = maxEl, high = sum;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(daysReq(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};