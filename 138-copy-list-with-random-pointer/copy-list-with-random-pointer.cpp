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
        Node* temp1 = head;
        while(temp1 != NULL) {
            if(temp1 -> random != NULL) {
                temp1 -> next -> random = temp1 -> random -> next;
            } else {
                temp1 -> next -> random = NULL;
            }
            temp1 = temp1 -> next -> next;
        }

        // 3 Connecting next pointers
        Node* temp2 = head;
        Node* res = new Node(0);
        Node* temp3 = res;
        while(temp2 != NULL) {
            res -> next = temp2 -> next;
            temp2 -> next = temp2 -> next -> next;
            temp2 = temp2 -> next;
            res = res -> next;
        }

        return temp3 -> next;
    }
};