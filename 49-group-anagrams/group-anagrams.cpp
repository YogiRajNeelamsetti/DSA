class Solution {
public:
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v) {
                // combine hashes (31 is a common multiplier)
                h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mpp;

        for(string &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());

            mpp[temp].push_back(s);
        }

        vector<vector<string>> res;

        for(auto &[temp, str] : mpp) {
            vector<string> st;
            for(string &s : str) {
                st.push_back(s);
            }
            res.push_back(st);
        }

        return res;
    }
};