class Solution {
public:
    void leftSmallest(vector<int> &arr, vector<int> &la, int n) {
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                
                s.pop();
            }
            la[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }
    }

    void rightSmallest(vector<int> &arr, vector<int> &ra, int n) {
        stack<int> s;
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ra[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
    }

    int generateArea(vector<int> &arr, int n) {

        vector<int> la(n, -1);
        vector<int> ra(n, -1);

        leftSmallest(arr, la, n);
        rightSmallest(arr, ra, n);

        int ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            ans = max(ans, (ra[i] - la[i] - 1) * arr[i]);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            maxArea = max(maxArea, generateArea(height, m));
        }

        return maxArea;
    }
};