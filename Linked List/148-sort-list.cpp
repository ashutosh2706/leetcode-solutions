class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // this problem should be solved with any O(nlogn) sorting algorithms
        vector<int> v;
        ListNode* t = head;
        while(t) {
            v.push_back(t->val);
            t=t->next;
        }
        sort(begin(v),end(v));
        t=head;
        for(int i=0; i<v.size(); i++) {
            t->val = v[i];
            t=t->next;
        }
        return head;
    }
};