class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        for(int r = 1; r <= numRows; r++) {
            vector<int> row(r);
            row[0] = row[r - 1] = 1;
            for(int i = 1; i < r - 1; i++) {
                row[i] = pascalTriangle[r - 2][i - 1] + pascalTriangle[r - 2][i];
            }
            pascalTriangle.push_back(row);
        }

        return pascalTriangle;
    }
};