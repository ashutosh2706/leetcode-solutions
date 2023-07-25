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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        if(k == 0) return head;
        int sz = 0;
        vector<int> vec;
        ListNode* tmp = head;
        while(tmp) {
            sz++;
            tmp = tmp->next;
        }

        int rot = k%sz;
        if(rot == 0) return head;
        vector<int> nodes(sz);
        tmp = head;
        int ind = 0;
        while(tmp) {
            int val = tmp->val;
            nodes[(ind+rot) % sz] = val;
            ind++;
            tmp = tmp->next;
        }
        ListNode* node = new ListNode(nodes[0]);
        ListNode* h = node;
        for(int i=1; i<nodes.size(); i++) {
            node->next = new ListNode(nodes[i]);
            node = node->next;
        }
        return h;
    }
};