class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> arr;

        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) {
                arr.push_back(asteroids[i]);
            } else {
                while(!arr.empty() && arr.back() > 0 && arr.back() < abs(asteroids[i])) {
                    arr.pop_back();
                }
                if(!arr.empty() && arr.back() == abs(asteroids[i])) {
                    arr.pop_back();
                } else if(arr.empty() || arr.back() < 0) {
                    arr.push_back(asteroids[i]);
                }
            }
        }

        return arr;
    }
};