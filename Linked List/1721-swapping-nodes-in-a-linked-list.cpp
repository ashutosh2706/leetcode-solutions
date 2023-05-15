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
    ListNode* swapNodes(ListNode* head, int k) {
        int sz = 0;
        ListNode *tmp = head;
        while(tmp) {
            sz++;
            tmp=tmp->next;
        }

        int front = k, back = sz-k+1, cnt = 0;
        tmp = head;
        ListNode *a = nullptr,*b = nullptr;
        while(tmp) {
            cnt++;
            if(cnt == front) a = tmp;
            else if(cnt == back) b = tmp;
            tmp = tmp->next;
            if(a && b) break;
        }
        if(a && b)
        swap(a->val, b->val);
        return head;

    }
};