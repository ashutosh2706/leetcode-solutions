linked-list-cycle/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> set;
        while(head) {
            if(set.count(head)) return 1;
            set.insert(head);
            head = head->next;
        }
        return 0;
    }
};