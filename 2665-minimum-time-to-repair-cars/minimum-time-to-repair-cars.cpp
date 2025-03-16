class Solution {
public:
    int freq[101] = {0}, minEl = 101, maxEl = 0;
    bool isPossible(int cars, long long target) {
        long long ans = 0;

        for(int i = minEl; i <= maxEl; i++) {
            ans += freq[i] * (long long)(sqrt(target / i));
            if (ans >= cars) return 1;
        }

        return ans >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        for(int ele : ranks) {
            if(ele < minEl) minEl = ele;
            if(ele > maxEl) maxEl = ele;
            freq[ele]++;
        }
        long long low = 1, high = 1LL * minEl * cars * cars;
        while(low < high) {
            long long mid = low + (high - low) / 2;

            if(isPossible(cars, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};