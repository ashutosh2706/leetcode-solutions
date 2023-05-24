class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 || l2) {
            int n1 = 0, n2 = 0;
            if(l1) n1 = l1->val;
            if(l2) n2 = l2->val;
            if(tail == NULL) {
                int sum = (n1+n2) % 10, carry = (n1+n2)/10;
                tail = new ListNode(sum);
                head = tail;
                tail->next = new ListNode(carry);
                tail=tail->next;
            } else {
                int value = tail->val;
                tail->val = (value+n1+n2) % 10;
                tail->next = new ListNode((value+n1+n2)/10);
                tail = tail->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        ListNode* tmp = head;
        while(tmp -> next != tail) tmp = tmp->next;
        if(tail->val == 0) tmp->next = NULL;
        return head;
    }
};