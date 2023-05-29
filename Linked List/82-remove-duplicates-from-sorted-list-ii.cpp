class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* tmp = head;
        ListNode *curr = NULL;
        ListNode* hea = NULL;
        while(tmp) {
            if(tmp->next == NULL || (tmp->val != tmp->next->val)) {
                if(curr == NULL) curr = tmp;
                else { curr->next = tmp; curr = curr->next; }
                tmp = tmp->next;
                if(hea == NULL) hea = curr;
            } else {
                int x = tmp->val;
                while(tmp && tmp->val == x) tmp = tmp -> next;
            }
        }
        if(curr) curr->next = NULL;
        return hea;
    }
};