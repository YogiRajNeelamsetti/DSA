class Node {
    public:
        Node* links[26];
        bool flag;

        Node() {
            for(int i = 0; i < 26; i++) links[i] = NULL;
            flag = false;
        }

        bool containKey(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!(node -> links[word[i] - 'a'])) {
                node -> put(word[i], new Node());
            }

            node = node -> links[word[i] - 'a'];
        }
        node -> setEnd();

        return;
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++) {
            if(!(node -> get(word[i]))) return false;

            node = node -> links[word[i] - 'a'];
        }

        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(!node -> get(prefix[i])) return false;

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