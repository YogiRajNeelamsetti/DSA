/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp = head;

        // 1 Insert nodes in between
        while(temp != NULL) {
            Node* copyNode = new Node(temp -> val);
            copyNode -> next = temp -> next;
            temp -> next = copyNode;
            temp = temp -> next -> next;
        }

        // 2 Connecting random pointers
        temp = head;
        while(temp != NULL) {
            if(temp -> random != NULL) {
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }

        // 3 Connecting next pointers
        temp = head;
        Node* res = new Node(0);
        Node* temp3 = res;
        while(temp != NULL) {
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
            res = res -> next;
        }

        return temp3 -> next;
    }
};