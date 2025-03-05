class Solution {
    int maxElement(vector<int> &piles) {
        int ans = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > ans) ans = piles[i];
        }
        return ans;
    }
    long long hours(vector<int> &piles, int h) {
        long long total = 0;

        for(int i = 0; i < piles.size(); i++) {
            total += (ceil((double)(piles[i]) / (double)(h)));
        }

        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            long long mid = (low + high) / 2;
            if(hours(piles, mid) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};