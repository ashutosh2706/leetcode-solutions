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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* tmp = head;
        while(tmp) {
            stk.push(tmp);
            tmp = tmp->next;
        }
        tmp = head;
        int pos = 0, N = stk.size();
        while(pos < floor(N/2)) {
            ListNode* temp = tmp->next;
            tmp -> next = stk.top();
            stk.pop();
            tmp->next->next = temp;
            tmp = tmp->next->next;
            pos++;
        }
        tmp->next = nullptr;



        // 1 -> 8 -> 3
    }
};