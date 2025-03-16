class Solution {
    bool isPossible(vector<int> &ranks, int cars, long long target) {
        long long ans = 0;

        for(int i = 0; i < ranks.size(); i++) {
            ans += floor(sqrt(target / ranks[i]));
        }

        return ans >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = LLONG_MAX;
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(isPossible(ranks, cars, mid)) {
                if(mid < ans) {
                    ans = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};