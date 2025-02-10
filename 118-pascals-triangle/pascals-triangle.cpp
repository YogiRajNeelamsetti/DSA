class Solution {
public:

    vector<int> nRow(int r) {
        long long ans = 1;
        vector<int> row;
        row.push_back(ans);
        for(int i = 1; i < r; i++) {
            ans = ans * (r - i);
            ans = ans / i;
            row.push_back(ans);
        }

        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        for(int i = 1; i <= numRows; i++) {
            vector<int> row = nRow(i);
            pascalTriangle.push_back(row);
        }

        return pascalTriangle;
    }
};