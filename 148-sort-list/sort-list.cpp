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
    ListNode* findMid(ListNode* head) {

        if(head == NULL || head -> next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while(list1 && list2) {
            if(list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            } else {
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }

        if(list1) {
            temp -> next = list1;
        } else {
            temp -> next = list2;
        }

        return head -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* mid = findMid(head);

        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};