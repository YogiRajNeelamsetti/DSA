/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> a;
        stack<ListNode*> b;

        
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != NULL) {
            a.push(tempA);
            tempA = tempA -> next;
        }
        while(tempB != NULL) {
            b.push(tempB);
            tempB = tempB -> next;
        }
        ListNode* ans = NULL;
        while(!a.empty() && !b.empty() && a.top() == b.top()) {
            ans = a.top();
            a.pop(), b.pop();
        }
        return ans;
    }
};