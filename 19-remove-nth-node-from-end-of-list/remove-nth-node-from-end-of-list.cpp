/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            len++;
            temp = temp -> next;
        }
        if(len == n) return head -> next;
        temp = head;
        int cnt = len - n;
        while(head != NULL) {
            cnt--;
            if(cnt == 0) break;
            head = head -> next;
        }
        head -> next = (head -> next -> next) ? head -> next -> next : NULL;
        return temp;
    }
};