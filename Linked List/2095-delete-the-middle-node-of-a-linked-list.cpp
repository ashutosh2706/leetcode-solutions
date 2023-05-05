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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        int nodes = 0, c = 0;
        ListNode* tmp = head;
        while(tmp) { tmp=tmp->next; nodes++; }
        nodes = floor(nodes/2);
        tmp = head;
        while(tmp && c != nodes-1) { tmp = tmp->next; c++; }
        if(tmp->next)
        tmp -> next = tmp->next->next;
        else tmp->next = nullptr;
        return head;
    }
};