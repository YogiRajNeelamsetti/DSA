class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        for(int r = 1; r <= numRows; r++) {
            long long ans = 1;
            vector<int> row;
            row.push_back(ans);
            for(int i = 1; i < r; i++) {
                ans = ans * (r - i);
                ans = ans / i;
                row.push_back(ans);
            }

            for(int ele : row) cout<<ele<<" ";
            cout<<endl;
            pascalTriangle.push_back(row);
        }

        return pascalTriangle;
    }
};