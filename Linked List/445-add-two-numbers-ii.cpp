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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> S1, S2;
        ListNode* head = l1;
        while(head) {
            S1.push(head->val);
            head = head->next;
        }
        head = l2;
         while(head) {
            S2.push(head->val);
            head = head->next;
        }
        ListNode* prev = nullptr;
        int carry = 0;
        while(!S1.empty() and !S2.empty()) {
            int sum = S1.top() + S2.top() + carry;
            S1.pop(); S2.pop();
            carry = sum / 10;
            if(!prev) {
                prev = new ListNode(sum % 10);
            } else {
                ListNode* new_node = new ListNode(sum % 10);
                new_node -> next = prev;
                prev = new_node;
            }
        }

        while(!S1.empty()) {
            int sum = S1.top() + carry; S1.pop();
            ListNode* node = new ListNode(sum % 10);
            node->next = prev;
            prev=node;
            carry = sum/10;
        }
        while(!S2.empty()) {
            int sum = S2.top() + carry; S2.pop();
            ListNode* node = new ListNode(sum % 10);
            node->next = prev;
            prev=node;
            carry = sum/10;
        }

        if(carry != 0) {
            ListNode* node = new ListNode(carry);
            node->next = prev;
            prev = node;
        }

        return prev;
    }
};