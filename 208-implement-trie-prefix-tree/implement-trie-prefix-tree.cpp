// class Node {
//     public:
//         Node* links[26];
//         bool flag = false;

//         bool containKey(char ch) {
//             return links[ch - 'a']
//         }

//         void put(char ch, Node* node) {
//             links[ch - 'a'] = node;
//         }

//         Node* get(char ch) {
//             return links[ch - 'a'];
//         }

//         void setEnd() {
//             flag = true;
//         }

//         bool isEnd() {
//             return flag;
//         }
// };

class Trie {
public:
    Trie* links[26];
    bool flag;

    Trie() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
        flag = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); i++) {
            if(!(node -> links[word[i] - 'a'])) {
                node -> links[word[i] - 'a'] = new Trie();
            }

            node = node -> links[word[i] - 'a'];
        }
        node -> flag = true;

        return;
    }
    
    bool search(string word) {
        Trie* node = this;

        for(int i = 0; i < word.size(); i++) {
            if(!(node -> links[word[i] - 'a'])) return false;

            node = node -> links[word[i] - 'a'];
        }

        return node -> flag;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i = 0; i < prefix.size(); i++) {
            if(!node -> links[prefix[i] - 'a']) return false;

            node = node -> links[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */