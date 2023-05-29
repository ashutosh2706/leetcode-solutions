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
        if(head->next == NULL) return n==0 ? head : NULL;
        ListNode* left = head;
        ListNode* right = head;
        while(n--)  if(right->next == NULL) {head=head->next; return head; } 
        else right = right->next;
        while(right->next) { left = left->next; right=right->next; }
        if(left->next) left->next = left->next->next;
        return head;
    }
};