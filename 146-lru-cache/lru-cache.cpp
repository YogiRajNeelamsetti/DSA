class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int key_, int val_) {
            key = key_;
            val = val_;

            prev = NULL;
            next = NULL;
        }
};


class LRUCache {
public:
    
    int cap;
    unordered_map<int, Node*> mpp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        head -> next = tail;
        tail -> prev = head;

        cap = capacity;
    }

    void addNode(Node* newNode) {
        Node* temp = head -> next;
        newNode -> prev = head;
        newNode -> next = temp;

        head -> next = newNode;
        temp -> prev = newNode;

    }

    void deleteNode(Node* delNode) {
        Node* delprev = delNode -> prev;
        Node* delnext = delNode -> next;

        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node* resNode = mpp[key];
            int res = resNode -> val;
            mpp.erase(key);

            deleteNode(resNode);
            addNode(resNode);

            mpp[key] = head -> next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* existing = mpp[key];
            mpp.erase(key);
            deleteNode(existing);
        }

        if(mpp.size() == cap) {
            mpp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        mpp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */