class Solution {
public:
    vector<vector<string>> ans;
    string b;
    unordered_map<string, int> mpp;

    void dfs(string word, vector<string> &seq) {
        if(word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        for(int i = 0; i < sz; i++) {
            char org = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        
        b = beginWord;
        q.push(beginWord);
        s.erase(beginWord);
        mpp[b] = 1;

        int sz = beginWord.size();

        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];

            if(word == endWord) {
                break;
            }

            for(int i = 0; i < sz; i++) {
                char org = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(s.count(word) > 0) {
                        q.push(word);
                        mpp[word] = steps + 1;
                        s.erase(word);
                    }
                }
                word[i] = org;
            }
        }

        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};