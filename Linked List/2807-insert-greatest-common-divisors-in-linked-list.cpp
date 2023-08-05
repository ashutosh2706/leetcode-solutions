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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;
        
        ListNode *tmp = head;
        
        while(head) {
            if(head->next == NULL) break;
            ListNode *n = new ListNode(__gcd(head->val, head->next->val));
            n->next = head->next;
            head->next = n;
            head = n->next;
            
        }
        return tmp;
    }
};